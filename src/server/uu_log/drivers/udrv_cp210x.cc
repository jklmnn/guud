
#include <drivers/cp210x.h>

Guud::Cp210x::Cp210x(Genode::Env &env, Genode::Heap &heap, Genode::Signal_context_capability sigc) :
    Guud::Uart(env, heap, sigc)
{
}

Genode::size_t Guud::Cp210x::tx(const char *line)
{
    return 0;
}

bool Guud::Cp210x::valid_device(Genode::uint16_t vendor, Genode::uint16_t device)
{
    return vendor == 0x10c4 && device == 0xea60;
}

bool Guud::Cp210x::initialize()
{
    Genode::log(__func__);
    Genode::uint16_t save = 0, test = 0;
    Usb::Interface &iface = _device.interface(0);
    iface.claim();
    read_reg<Genode::uint16_t>(iface, 4, &save);
    Genode::log("saved value ", Genode::Hex(save));
    write_reg<Genode::uint16_t>(iface, 3, 0x800);
    read_reg<Genode::uint16_t>(iface, 4, &test);
    Genode::log("tested value ", Genode::Hex(test));
    write_reg<Genode::uint16_t>(iface, 3, save);

    Genode::uint32_t baud = 0;
    write_reg<Genode::uint32_t>(iface, 0x1e, 115200);
    read_reg<Genode::uint32_t>(iface, 0x1d, &baud);
    Genode::log("baud ", baud);

    return true;
}
