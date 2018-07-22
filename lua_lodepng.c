#define llodepng
#define LUA_LIB

#include <lua/lauxlib.h>
#include <lua/lua.h>
#include <stdio.h>

#include "lodepng.h"

static int decode32(lua_State *L)
{
    size_t pngsize;
    const unsigned char *pngfile =
        (const unsigned char *)lua_tolstring(L, 1, &pngsize);

    unsigned error;
    unsigned char *image;
    unsigned width, height;
    error = lodepng_decode32(&image, &width, &height, pngfile, pngsize);
    if (error)
    {
        lua_pushnil(L);
        return 1;
    }
    else
    {
        lua_newtable(L);
        lua_pushliteral(L, "width");
        lua_pushinteger(L, width);
        lua_settable(L, -3);
        lua_pushliteral(L, "height");
        lua_pushinteger(L, height);
        lua_settable(L, -3);
        lua_pushliteral(L, "data");
        lua_pushlstring(L, (char *)image, width * height * 4);
        lua_settable(L, -3);
        return 1;
    }
}

static const luaL_Reg lodepng[] = {
    {"decode32", decode32},
    {NULL, NULL},
};

LUAMOD_API int luaopen_lodepng(lua_State *L)
{
    luaL_newlib(L, lodepng);
    return 1;
}
