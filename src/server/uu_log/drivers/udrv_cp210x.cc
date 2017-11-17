
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
    read_reg_16(iface, 4, &save);
    Genode::log("saved value ", Genode::Hex(save));
    write_reg_16(iface, 3, 0x800);
    read_reg_16(iface, 4, &test);
    Genode::log("tested value ", Genode::Hex(test));
    write_reg_16(iface, 3, save);
    return true;
}

void Guud::Cp210x::write_reg_16(Usb::Interface &iface, Genode::uint8_t reg, Genode::uint16_t value, Genode::uint16_t index)
{
    Usb::Packet_descriptor packet = iface.alloc(0);
    Genode::uint8_t type = Usb::ENDPOINT_OUT | Usb::TYPE_VENDOR | Usb::RECIPIENT_DEVICE;
    iface.control_transfer(packet, type, reg, value, index, 100);
    iface.release(packet);
}

void Guud::Cp210x::read_reg_16(Usb::Interface &iface, Genode::uint8_t reg, Genode::uint16_t *value, Genode::uint16_t index)
{
    Usb::Packet_descriptor packet = iface.alloc(2);
    Genode::uint8_t type = Usb::ENDPOINT_IN | Usb::TYPE_VENDOR | Usb::RECIPIENT_DEVICE;
    iface.control_transfer(packet, type, reg, 0, index, 100);
    *value = *(Genode::uint16_t*)iface.content(packet);
    iface.release(packet);
}

