
#include "app/spell_engine.h"

#include <assert.h>

CSpellEngine& CSpellEngine::GetInstance()
{
    static CSpellEngine s_Singleon;
    return s_Singleon;
}

// -----------------------------------------------------------------------------

CSpellEngine::CSpellEngine()
{

}

// -----------------------------------------------------------------------------

CSpellEngine::~CSpellEngine()
{

}

// -----------------------------------------------------------------------------

void CSpellEngine::OnStart()
{
    Lua::Load("../resources/scripts/fireball.lua");

    Lua::Register("Fire", CSpellEngine::Fire);
}

// -----------------------------------------------------------------------------

void CSpellEngine::OnExit()
{
}

// -----------------------------------------------------------------------------

void CSpellEngine::Update()
{
    Lua::Call("Update");
}

// -----------------------------------------------------------------------------

int CSpellEngine::Fire(lua_State* _pScript)
{
    int NumberOfArguments = lua_gettop(_pScript);

    assert(NumberOfArguments > 0);

    const char* pScriptname = lua_tostring (_pScript, 1);
    int         IntValue    = lua_tointeger(_pScript, 2);

    printf("%s called: %i health get lost.\n", pScriptname, IntValue);

    // CSpellEngine::GetInstance().Update();

    lua_pushinteger(_pScript, 5);
    lua_pushinteger(_pScript, 10);

    return 2;
}