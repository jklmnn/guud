
#ifndef _GUUD_CP210X_H_
#define _GUUD_CP210X_H_

#include <uu_uart.h>

namespace Guud {
    class Cp210x;
};

class Guud::Cp210x : public Guud::Uart
{
    private:

        bool valid_device(Genode::uint16_t, Genode::uint16_t) override;
        bool initialize() override;

        template <typename T>
        void write_reg(Usb::Interface& iface, Genode::uint8_t reg, T value, Genode::uint16_t index = 0)
        {
            Usb::Packet_descriptor packet = iface.alloc(sizeof(T));
            Genode::uint8_t type = Usb::ENDPOINT_OUT | Usb::TYPE_VENDOR | Usb::RECIPIENT_DEVICE;
            *(T*)iface.content(packet) = value;
            iface.control_transfer(packet, type, reg, value, index, 100);
            iface.release(packet);
        }

        template <typename T>
        void read_reg(Usb::Interface& iface, Genode::uint8_t reg, T* value, Genode::uint16_t index = 0)
        {
            Usb::Packet_descriptor packet = iface.alloc(2);
            Genode::uint8_t type = Usb::ENDPOINT_IN | Usb::TYPE_VENDOR | Usb::RECIPIENT_DEVICE;
            iface.control_transfer(packet, type, reg, 0, index, 100);
            *value = *(T*)iface.content(packet);
            iface.release(packet); 
        }

    public:
        Cp210x(Genode::Env &, Genode::Heap&, Genode::Signal_context_capability);
        
        Genode::size_t tx(const char*) override;
};

#endif //_GUUD_CP210X_H_
