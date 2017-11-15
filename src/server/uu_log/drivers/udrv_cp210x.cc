
#include <drivers/cp210x.h>

Guud::Cp210x::Cp210x(Genode::Env &env) :
    Guud::Uart(env)
{
    
}

Genode::size_t Guud::Cp210x::tx(const char *line)
{
    return 0;
}
