
#include <base/log.h>
#include <base/component.h>
#include <base/heap.h>
#include <base/signal.h>

#include <drivers/cp210x.h>

namespace Guud {
    struct Main;
};

struct Guud::Main
{
    Genode::Env &_env;

    Genode::Heap _heap { _env.ram(), _env.rm() };

    void handle() {}

    Genode::Signal_handler<Guud::Main> _sigh {
        _env.ep(),
        *this,
        &Guud::Main::handle
    };

    Guud::Cp210x _uart {
        _env,
        _heap,
        _sigh
    };

    Main(Genode::Env &env) : _env(env)
    {
        Genode::log("guud");
    }
};

void Component::construct(Genode::Env &env)
{
    static Guud::Main main(env);
}
