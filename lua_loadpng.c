#define llodepng
#define LUA_LIB

#include <lua/lua.h>
#include <lua/lauxlib.h>

#include <stdio.h>

static int decode32_file(lua_State *L)
{
    printf("lodepng_decode32_file\n");
    return 0;
}

static const luaL_Reg loadpng[] = {
    {"lodepng_decode32_file", decode32_file},
    {NULL, NULL},
};

LUAMOD_API int luaopen_loadpng(lua_State *L)
{
    luaL_newlib(L, loadpng);
    return 1;
}
