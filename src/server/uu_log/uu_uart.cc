
#include <uu_uart.h>


Guud::Uart::Uart(Genode::Env &env, Genode::Allocator &alloc, Genode::Signal_context_capability sigc) :
    _sigc(sigc),
    _sigh(env.ep(), *this, &Guud::Uart::handle_state_change),
    _alloc(&alloc),
    _usb(env, &_alloc, "guud", 16*4096, _sigh),
    _device(&_alloc, _usb, env.ep())
{
}
