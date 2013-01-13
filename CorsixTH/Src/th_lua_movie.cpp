/*
Copyright (c) 2012 Stephen Baker

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "th_lua_internal.h"
#include "th_movie.h"

static int l_movie_new(lua_State *L)
{
    luaT_stdnew<THMovie>(L, luaT_environindex, true);
    return 1;
}

static int l_movie_load(lua_State *L)
{
    THMovie *pMovie = luaT_testuserdata<THMovie>(L);
    const char* filepath = lua_tolstring(L, 2, NULL);
    pMovie->load(filepath);
    return 1;
}

static int l_movie_play(lua_State *L)
{
    THMovie *pMovie = luaT_testuserdata<THMovie>(L);
    pMovie->play(luaL_checkinteger(L, 2), luaL_checkinteger(L, 3), luaL_checkinteger(L, 4), luaL_checkinteger(L, 5), luaL_checkinteger(L, 6));
    return 1;
}

static int l_movie_unload(lua_State *L)
{
    THMovie *pMovie = luaT_testuserdata<THMovie>(L);
    pMovie->unload();
    return 1;
}

static int l_movie_get_native_width(lua_State *L)
{
    THMovie *pMovie = luaT_testuserdata<THMovie>(L);
    lua_pushinteger(L, pMovie->getNativeWidth());
    return 1;
}

static int l_movie_get_native_height(lua_State *L)
{
    THMovie *pMovie = luaT_testuserdata<THMovie>(L);
    lua_pushinteger(L, pMovie->getNativeHeight());
    return 1;
}

static int l_movie_has_audio_track(lua_State *L)
{
    THMovie *pMovie = luaT_testuserdata<THMovie>(L);
    lua_pushboolean(L, pMovie->hasAudioTrack());
    return 1;
}

static int l_movie_allocate_picture(lua_State *L)
{
    THMovie *pMovie = luaT_testuserdata<THMovie>(L);
    pMovie->allocatePicture();
    return 1;
}

static int l_movie_stop(lua_State *L)
{
    THMovie *pVideo = luaT_testuserdata<THMovie>(L);
    pVideo->stop();
    return 1;
}

static int l_movie_refresh(lua_State *L)
{
    THMovie *pMovie = luaT_testuserdata<THMovie>(L);
    pMovie->refresh();
    return 1;
}

void THLuaRegisterMovie(const THLuaRegisterState_t *pState)
{
    luaT_class(THMovie, l_movie_new, "moviePlayer", MT_Movie);
    luaT_setfunction(l_movie_stop, "stop");
    luaT_setfunction(l_movie_allocate_picture, "allocatePicture");
    luaT_setfunction(l_movie_refresh, "refresh");
    luaT_setfunction(l_movie_load, "load");
    luaT_setfunction(l_movie_unload, "unload");
    luaT_setfunction(l_movie_play, "play");
    luaT_setfunction(l_movie_get_native_width, "getNativeWidth");
    luaT_setfunction(l_movie_get_native_height, "getNativeHeight");
    luaT_setfunction(l_movie_has_audio_track, "hasAudioTrack");
    luaT_endclass();
}