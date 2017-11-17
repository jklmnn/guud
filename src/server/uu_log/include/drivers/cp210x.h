
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

        void write_reg_16(Usb::Interface&, Genode::uint8_t, Genode::uint16_t, Genode::uint16_t = 0);
        void read_reg_16(Usb::Interface&, Genode::uint8_t, Genode::uint16_t*, Genode::uint16_t = 0);

    public:
        Cp210x(Genode::Env &, Genode::Heap&, Genode::Signal_context_capability);
        
        Genode::size_t tx(const char*) override;
};

#endif //_GUUD_CP210X_H_
