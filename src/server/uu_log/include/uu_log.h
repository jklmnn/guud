
#ifndef _GUUD_UU_LOG_H_
#define _GUUD_UU_LOG_H_

#include <root/component.h>

#include <log_session/log_session.h>

#include <uu_uart.h>

namespace Guud {
    class Log_component;
    class Log_root;
};

class Guud::Log_component : public Genode::Rpc_object<Genode::Log_session>
{
    private:

        Guud::Uart &_uart;

    public:

        Log_component(const char *label, Genode::Env &env, Guud::Uart &uart) :
            _uart(uart)
        { }

        Genode::size_t write(String const &);
};

class Guud::Log_root : public Genode::Root_component<Guud::Log_component>
{
    private:

        Genode::Env &_env;
        Guud::Uart &_uart;

    protected:

        Guud::Log_component *_create_session(const char*);

    public:

        Log_root(Genode::Env &env, Genode::Allocator &md_alloc, Guud::Uart &uart) : 
            Genode::Root_component<Guud::Log_component>(env.ep(), md_alloc),
            _env(env),
            _uart(uart)
        { }
};

#endif //_GUUD_UU_LOG_H_
