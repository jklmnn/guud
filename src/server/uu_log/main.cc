
#include <base/log.h>
#include <base/component.h>

namespace Guud {
    struct Main;
};

struct Guud::Main
{
    Main(Genode::Env &env)
    {
        Genode::log("guud");
    }
};

void Component::construct(Genode::Env &env)
{
    static Guud::Main main(env);
}
