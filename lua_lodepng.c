#define llodepng
#define LUA_LIB

#include <lua/lua.h>
#include <lua/lauxlib.h>

#include <stdio.h>

static int decode32_file(lua_State *L)
{
    (void)(L);
    printf("lodepng_decode32_file\n");
    return 0;
}

static const luaL_Reg lodepng[] = {
    {"lodepng_decode32_file", decode32_file},
    {NULL, NULL},
};

LUAMOD_API int luaopen_lodepng(lua_State *L)
{
    luaL_newlib(L, lodepng);
    return 1;
}
