
#pragma once

#include "lua/lua.hpp"

// TODO by tschwandt [6.6.2013]:
// Only an example of an c interface of lua -> implemantation and improvements needed

namespace Lua
{
    typedef int (*CRegisterFunction)(lua_State *_pScript);

    void Load    (const char* _pScript);
    void Register(const char* _pFunction, CRegisterFunction _Function);

    void PushNumber (int _IntValue);
    void PushNumber (unsigned int _IntValue);
    void PushNumber (float _FloatValue);
    void PushNumber (double _DoubleValue);
    void PushBoolean(bool _Booleanvalue);
    void PushString (const char* _pStringValue);     

    void Call(const char* _pFunction);

    void PullNumber (int& _rIntValue);
    void PullNumber (unsigned int& _rIntValue);
    void PullNumber (float& _rFloatValue);
    void PullNumber (double& _rDoubleValue);
    void PullBoolean(bool& _rBooleanvalue);
    void PullString (const char* _pStringValue, unsigned int& _rLengthOfString); 

    bool IsNumber ();
    bool IsBoolean();
    bool IsString ();
} // namespace Lua