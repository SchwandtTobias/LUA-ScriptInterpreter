
#pragma once

#include "app/script.h"

class CSpellEngine
{
public:
    static CSpellEngine& GetInstance();

public:
    void OnStart();
    void OnExit();
    void Update();

private:
    CSpellEngine();
   ~CSpellEngine();

   static int Fire(lua_State* _pScript);
};