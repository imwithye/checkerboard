#define llodepng
#define LUA_LIB

#include <lua/lua.h>
#include <lua/lauxlib.h>
#include <stdio.h>

#include "lodepng.h"

static int decode32_file(lua_State *L)
{
    size_t filename_length;
    const char *filename = luaL_checklstring(L, 1, &filename_length);

    unsigned error;
    unsigned char *image;
    unsigned width, height;
    error = lodepng_decode32_file(&image, &width, &height, filename);
    if (error)
    {
        lua_pushnil(L);
        lua_pushinteger(L, 0);
        lua_pushinteger(L, 0);
        lua_pushinteger(L, error);
        return 4;
    }
    else
    {
        lua_pushliteral(L, "yeah~");
        lua_pushinteger(L, 0);
        lua_pushinteger(L, 0);
        lua_pushinteger(L, error);
        return 4;
    }
}

static int error_text(lua_State *L)
{
    const int error_code = luaL_checkinteger(L, 1);
    const char *error_message = lodepng_error_text(error_code);
    lua_pushstring(L, error_message);
    return 1;
}

static const luaL_Reg lodepng[] = {
    {"decode32_file", decode32_file},
    {"error_text", error_text},
    {NULL, NULL},
};

LUAMOD_API int luaopen_lodepng(lua_State *L)
{
    luaL_newlib(L, lodepng);
    return 1;
}
