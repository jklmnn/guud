
#include <uu_uart.h>


Guud::Uart::Uart(Genode::Env &env, Genode::Heap &heap, Genode::Signal_context_capability sigc) :
    _sigc(sigc),
    _sigh(env.ep(), *this, &Guud::Uart::handle_state_change),
    _heap(heap),
    _alloc(&_heap),
    _usb(env, &_alloc, "guud", 16*4096, _sigh),
    _device(&_heap, _usb, env.ep())
{
}

void Guud::Uart::handle_state_change()
{
    if(!_usb.plugged())
        return;

    _device.update_config();
    Genode::log("State changed: ",
            Genode::Hex(_device.device_descr.vendor_id), ":",
            Genode::Hex(_device.device_descr.product_id));

    if(valid_device(_device.device_descr.vendor_id,
                _device.device_descr.product_id))
        if(initialize())
            Genode::Signal_transmitter(_sigc).submit();
}
