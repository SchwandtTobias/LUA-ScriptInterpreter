
#include "lua/lua.hpp"
#include "app/spell_engine.h"

// void AccountClass();
// void ReturnValues();
// void HelloWorld();

void main()
{
    CSpellEngine::GetInstance().OnStart();

    CSpellEngine::GetInstance().Update();

    // CSpellEngine::GetInstance().Update(); //Fails!

    CSpellEngine::GetInstance().OnExit();
}

// void AccountClass()
// {
// 
//     int Error;
// 
//     // -----------------------------------------------------------------------------
//     // Start lua
//     // -----------------------------------------------------------------------------
//     lua_State* pLuaState = luaL_newstate();
// 
//     // -----------------------------------------------------------------------------
//     // Set libraries
//     // -----------------------------------------------------------------------------
//     static const luaL_Reg LuaLibraries[] =
//     {
//         {
//             "base", luaopen_base
//         },
//         {
//             "io", luaopen_io
//             },
//             {
//                 0, 0
//             }
//     };
// 
//     const luaL_Reg* pLibraries = LuaLibraries;
// 
//     for (; pLibraries->func != 0 ; ++pLibraries)
//     {
//         luaL_requiref(pLuaState, pLibraries->name, pLibraries->func, 1);
//         lua_settop(pLuaState, 0);
//     }
// 
//     // -----------------------------------------------------------------------------
//     // Compile script
//     // -----------------------------------------------------------------------------
//     Error = luaL_loadfile(pLuaState, "..\\resources\\scripts\\account_class.lua");
// 
//     if (Error)
//     {
//         printf("%s\n", lua_tostring(pLuaState, -1));
//     }
// 
//     // -----------------------------------------------------------------------------
//     // Run script
//     // -----------------------------------------------------------------------------
//     Error = lua_pcall(pLuaState, 0, LUA_MULTRET, 0);
// 
//     if (Error)
//     {
//         printf("%s\n", lua_tostring(pLuaState, -1));
//     }
// 
//     // -----------------------------------------------------------------------------
//     // Read return values
//     // -----------------------------------------------------------------------------
//     while(lua_gettop(pLuaState))
//     {
//         switch(lua_type(pLuaState, lua_gettop(pLuaState)))
//         {
// 
//         case LUA_TNUMBER:
//             printf("Number : %f", lua_tonumber(pLuaState, lua_gettop(pLuaState)));
//             break;
// 
//         case LUA_TTABLE:
//             printf("Table");
//             break;
// 
//         case LUA_TSTRING:
//             printf("String : %s", lua_tostring(pLuaState, lua_gettop(pLuaState)));
//             break;
// 
//         case LUA_TBOOLEAN:
//             printf("Boolean: %i", lua_toboolean(pLuaState, lua_gettop(pLuaState)));
//             break;
// 
//         default:
//             printf("Undefined");
// 
//         }
// 
//         lua_pop(pLuaState, 1);
// 
//         printf("\n");
//     }
// 
//     
// 
//     // -----------------------------------------------------------------------------
//     // Close LUA
//     // -----------------------------------------------------------------------------
//     lua_close(pLuaState);
// }
// 
// void ReturnValues()
// {
// 
//     int Error;
// 
//     // -----------------------------------------------------------------------------
//     // Start lua
//     // -----------------------------------------------------------------------------
//     lua_State* pLuaState = luaL_newstate();
// 
//     // -----------------------------------------------------------------------------
//     // Set libraries
//     // -----------------------------------------------------------------------------
//     static const luaL_Reg LuaLibraries[] =
//     {
//         {
//             "base", luaopen_base
//         },
//         {
//             "io", luaopen_io
//         },
//         {
//             0, 0
//         }
//     };
// 
//     const luaL_Reg* pLibraries = LuaLibraries;
// 
//     for (; pLibraries->func != 0 ; ++pLibraries)
//     {
//         luaL_requiref(pLuaState, pLibraries->name, pLibraries->func, 1);
//         lua_settop(pLuaState, 0);
//     }
// 
//     // -----------------------------------------------------------------------------
//     // Compile script
//     // -----------------------------------------------------------------------------
//     Error = luaL_loadfile(pLuaState, "..\\resources\\scripts\\return_values.lua");
// 
//     if (Error)
//     {
//         printf("%s\n", lua_tostring(pLuaState, -1));
//     }
// 
//     // -----------------------------------------------------------------------------
//     // Set args
//     // -----------------------------------------------------------------------------
//     lua_newtable    (pLuaState);
//    
//     lua_pushnumber  (pLuaState, 1);
//     lua_pushnumber  (pLuaState, 49);
//     lua_settable    (pLuaState, -3);
// 
//     lua_pushnumber  (pLuaState, 2);
//     lua_pushstring  (pLuaState, "Life is a beach");
//     lua_settable    (pLuaState, -3);
// 
//     lua_pushnumber  (pLuaState, 3);
//     lua_pushstring  (pLuaState, "Life is a kiss");
//     lua_settable    (pLuaState, -3);
// 
//     lua_setglobal   (pLuaState, "arg");
// 
//     // -----------------------------------------------------------------------------
//     // Run script
//     // -----------------------------------------------------------------------------
//     Error = lua_pcall(pLuaState, 0, LUA_MULTRET, 0);
// 
//     if (Error)
//     {
//         printf("%s\n", lua_tostring(pLuaState, -1));
//     }
// 
//     // -----------------------------------------------------------------------------
//     // Read return values
//     // -----------------------------------------------------------------------------
//     while(lua_gettop(pLuaState))
//     {
//         switch(lua_type(pLuaState, lua_gettop(pLuaState)))
//         {
// 
//         case LUA_TNUMBER:
//             printf("Number : %f", lua_tonumber(pLuaState, lua_gettop(pLuaState)));
//             break;
// 
//         case LUA_TTABLE:
//             printf("Table");
//             break;
// 
//         case LUA_TSTRING:
//             printf("String : %s", lua_tostring(pLuaState, lua_gettop(pLuaState)));
//             break;
// 
//         case LUA_TBOOLEAN:
//             printf("Boolean: %i", lua_toboolean(pLuaState, lua_gettop(pLuaState)));
//             break;
// 
//         default:
//             printf("Undefined");
// 
//         }
// 
//         lua_pop(pLuaState, 1);
// 
//         printf("\n");
//     }
// 
//     // -----------------------------------------------------------------------------
//     // Close LUA
//     // -----------------------------------------------------------------------------
//     lua_close(pLuaState);
// }
// 
// void HelloWorld()
// {
//     lua_State *LuaState;
//     LuaState = luaL_newstate();
// 
//     // load Lua libraries
//     static const luaL_Reg LuaLibaries[] =
//     {
//         { "base", luaopen_base },
//         { NULL, NULL}
//     };
// 
//     const luaL_Reg *Libaries = LuaLibaries;
//     for(; Libaries->func != NULL; Libaries++)
//     {
//         Libaries->func(LuaState);
//         lua_settop(LuaState, 0);
//     }
// 
//     // run the Lua script
//     int Error = luaL_dofile(LuaState, "..\\resources\\scripts\\hello.lua");
// 
//     if (Error == 1)
//     {
//         printf("%s\n", lua_tostring(LuaState, -1));
//     }
// 
//     // close the Lua state
//     lua_close(LuaState);
// }