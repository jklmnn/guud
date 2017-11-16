
#include <drivers/cp210x.h>

Guud::Cp210x::Cp210x(Genode::Env &env, Genode::Allocator &alloc, Genode::Signal_context_capability sigc) :
    Guud::Uart(env, alloc, sigc)
{
    
}

Genode::size_t Guud::Cp210x::tx(const char *line)
{
    return 0;
}
