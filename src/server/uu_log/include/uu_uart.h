
#ifndef _GUUD_UU_UART_H_
#define _GUUD_UU_UART_H_

namespace Guud {
    class Uart;
}

class Guud::Uart
{
    public:
        Uart(Genode::uint16_t, Genode::uint16_t) {}

        virtual Genode::size_t tx(const char*) = 0;
};

#endif //_GUUD_UU_UART_H_
