#define llodepng
#define LUA_LIB

#include <lua/lua.h>
#include <lua/lauxlib.h>
#include <stdio.h>

#include "lodepng.h"

static int load_file(lua_State *L)
{
    size_t filename_length;
    const char *filename = luaL_checklstring(L, 1, &filename_length);

    unsigned error;
    unsigned char *pngfile;
    size_t pngsize;
    error = lodepng_load_file(&pngfile, &pngsize, filename);
    if (error)
    {
        lua_pushnil(L);
        lua_pushinteger(L, 0);
        lua_pushinteger(L, error);
        return 3;
    }
    else
    {
        lua_pushlightuserdata(L, pngfile);
        lua_pushinteger(L, pngsize);
        lua_pushinteger(L, error);
        return 3;
    }
}

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
        lua_pushlightuserdata(L, image);
        lua_pushinteger(L, width);
        lua_pushinteger(L, height);
        lua_pushinteger(L, error);
        return 4;
    }
}

static int decode32(lua_State *L)
{
    const unsigned char *pngfile = lua_touserdata(L, 1);
    const size_t pngsize = lua_tointeger(L, 2);

    unsigned error;
    unsigned char *image;
    unsigned width, height;
    error = lodepng_decode32(&image, &width, &height, pngfile, pngsize);
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
        lua_pushlightuserdata(L, image);
        lua_pushinteger(L, width);
        lua_pushinteger(L, height);
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
    {"load_file", load_file},
    {"decode32_file", decode32_file},
    {"decode32", decode32},
    {"error_text", error_text},
    {NULL, NULL},
};

LUAMOD_API int luaopen_lodepng(lua_State *L)
{
    luaL_newlib(L, lodepng);
    return 1;
}
