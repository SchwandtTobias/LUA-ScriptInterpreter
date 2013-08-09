
#include "app/script.h"

#include <assert.h>

namespace
{
    class CState
    {
    public:
        typedef int (*CRegisterFunction)(lua_State *_pScript);

    public:
        static CState& GetInstance();

    public:
        void Load    (const char* _pScript);
        void Register(const char* _pFunction, CRegisterFunction _Function);

    public:
        void PushNumber (int _IntValue);
        void PushNumber (unsigned int _IntValue);
        void PushNumber (float _FloatValue);
        void PushNumber (double _DoubleValue);
        void PushBoolean(bool _Booleanvalue);
        void PushString (const char* _pStringValue);     

    public:
        void Call(const char* _pFunction);

    public:
        void PullNumber (int& _rIntValue) const;
        void PullNumber (unsigned int& _rIntValue) const;
        void PullNumber (float& _rFloatValue) const;
        void PullNumber (double& _rDoubleValue) const;
        void PullBoolean(bool& _rBooleanvalue) const;
        void PullString (const char* _pStringValue, unsigned int& _rLengthOfString) const; 

    public:
        bool IsNumber () const;
        bool IsBoolean() const;
        bool IsString () const;

    private:
        lua_State*   m_pLuaState;
        unsigned int m_NumberOfArguments;

    private:
        CState();
       ~CState();
    };
} // namespace

namespace
{
    CState& CState::GetInstance()
    {
        static CState s_Singleton;
        return s_Singleton;
    }

    // -----------------------------------------------------------------------------

    CState::CState()
        : m_pLuaState        (0)
        , m_NumberOfArguments(0)
    {
        // -----------------------------------------------------------------------------
        // Start lua
        // -----------------------------------------------------------------------------
        m_pLuaState = luaL_newstate();

        // -----------------------------------------------------------------------------
        // Set libraries
        // -----------------------------------------------------------------------------
        const luaL_Reg LuaLibraries[] =
        {
            {
                "base", luaopen_base
            },
            {
                "io", luaopen_io
            },
            {
                0, 0
            }
        };

        const luaL_Reg* pLibraries = LuaLibraries;

        for (; pLibraries->func != 0 ; ++pLibraries)
        {
            luaL_requiref(m_pLuaState, pLibraries->name, pLibraries->func, 1);
            lua_settop(m_pLuaState, 0);
        }
    }

    // -----------------------------------------------------------------------------

    CState::~CState()
    {
        // -----------------------------------------------------------------------------
        // Close LUA
        // -----------------------------------------------------------------------------
        lua_close(m_pLuaState);
    }

    // -----------------------------------------------------------------------------

    void CState::Load(const char* _pScript)
    {
        int Error;

        // -----------------------------------------------------------------------------
        // Compile script
        // -----------------------------------------------------------------------------
        Error = luaL_loadfile(m_pLuaState, _pScript);

        // TODO by tschwandt [6.6.2013]:
        // load scipt not from file.
        
        // TODO by tschwandt [6.6.2013]:
        // setup metatable, registry table or something like this to reload a compiled script

        assert(Error == 0);
    }

    // -----------------------------------------------------------------------------

    void CState::Register(const char* _pFunction, CRegisterFunction _Function)
    {
        // TODO by tschwandt [6.6.2013]:
        // find a better solution... maybe use defines to register a function (brilliant?)

        lua_register(m_pLuaState, _pFunction, _Function);
    }

    // -----------------------------------------------------------------------------

    void CState::PushNumber(int _IntValue)
    {

    }

    // -----------------------------------------------------------------------------

    void CState::PushNumber(unsigned int _IntValue)
    {

    }

    // -----------------------------------------------------------------------------

    void CState::PushNumber(float _FloatValue)
    {

    }

    // -----------------------------------------------------------------------------

    void CState::PushNumber(double _DoubleValue)
    {

    }

    // -----------------------------------------------------------------------------

    void CState::PushBoolean(bool _Booleanvalue)
    {

    }

    // -----------------------------------------------------------------------------

    void CState::PushString(const char* _pStringValue)
    {

    }

    // -----------------------------------------------------------------------------

    void CState::Call(const char* _pFunction)
    {
        int Error;

        // TODO by tschwandt [6.6.2013]:
        // reset stack pointer or set pointer to function (use defined table)

        Error = lua_pcall(m_pLuaState, 0, 0, 0);

        assert(Error == 0);
    }

    // -----------------------------------------------------------------------------

    void CState::PullNumber(int& _rIntValue) const
    {

    }

    // -----------------------------------------------------------------------------

    void CState::PullNumber(unsigned int& _rIntValue) const
    {

    }

    // -----------------------------------------------------------------------------

    void CState::PullNumber(float& _rFloatValue) const
    {

    }

    // -----------------------------------------------------------------------------

    void CState::PullNumber(double& _rDoubleValue) const
    {

    }

    // -----------------------------------------------------------------------------

    void CState::PullBoolean(bool& _rBooleanvalue) const
    {

    }

    // -----------------------------------------------------------------------------

    void CState::PullString(const char* _pStringValue, unsigned int& _rLengthOfString) const
    {

    }

    // -----------------------------------------------------------------------------

    bool CState::IsNumber() const
    {
        return false;
    }

    // -----------------------------------------------------------------------------

    bool CState::IsBoolean() const
    {
        return false;
    }

    // -----------------------------------------------------------------------------

    bool CState::IsString() const
    {
        return false;
    }
} // namespace


namespace Lua
{
    void Load(const char* _pScript)
    {
        CState::GetInstance().Load(_pScript);
    }

    // -----------------------------------------------------------------------------

    void Register(const char* _pFunction, CRegisterFunction _Function)
    {
        CState::GetInstance().Register(_pFunction, _Function);
    }

    // -----------------------------------------------------------------------------

    void PushNumber (int _IntValue)
    {
        CState::GetInstance().PushNumber(_IntValue);
    }

    // -----------------------------------------------------------------------------

    void PushNumber (unsigned int _IntValue)
    {
        CState::GetInstance().PushNumber(_IntValue);
    }

    // -----------------------------------------------------------------------------

    void PushNumber (float _FloatValue)
    {
        CState::GetInstance().PushNumber(_FloatValue);
    }

    // -----------------------------------------------------------------------------

    void PushNumber (double _DoubleValue)
    {
        CState::GetInstance().PushNumber(_DoubleValue);
    }

    // -----------------------------------------------------------------------------

    void PushBoolean(bool _Booleanvalue)
    {
        CState::GetInstance().PullBoolean(_Booleanvalue);
    }

    // -----------------------------------------------------------------------------

    void PushString (const char* _pStringValue)
    {
        CState::GetInstance().PushString(_pStringValue);
    }

    // -----------------------------------------------------------------------------     

    void Call(const char* _pFunction)
    {
        CState::GetInstance().Call(_pFunction);
    }

    // -----------------------------------------------------------------------------

    void PullNumber (int& _rIntValue)
    {
        CState::GetInstance().PullNumber(_rIntValue);
    }

    // -----------------------------------------------------------------------------

    void PullNumber (unsigned int& _rIntValue)
    {
        CState::GetInstance().PullNumber(_rIntValue);
    }

    // -----------------------------------------------------------------------------

    void PullNumber (float& _rFloatValue)
    {
        CState::GetInstance().PullNumber(_rFloatValue);
    }

    // -----------------------------------------------------------------------------

    void PullNumber (double& _rDoubleValue)
    {
        CState::GetInstance().PullNumber(_rDoubleValue);
    }

    // -----------------------------------------------------------------------------

    void PullBoolean(bool& _rBooleanvalue)
    {
        CState::GetInstance().PullBoolean(_rBooleanvalue);
    }

    // -----------------------------------------------------------------------------

    void PullString (const char* _pStringValue, unsigned int& _rLengthOfString)
    {
        CState::GetInstance().PullString(_pStringValue, _rLengthOfString);
    }

    // -----------------------------------------------------------------------------

    bool IsNumber ()
    {
        return CState::GetInstance().IsNumber();
    }

    // -----------------------------------------------------------------------------

    bool IsBoolean()
    {
        return CState::GetInstance().IsBoolean();
    }

    // -----------------------------------------------------------------------------

    bool IsString ()
    {
        return CState::GetInstance().IsString();
    }
} // namespace Lua