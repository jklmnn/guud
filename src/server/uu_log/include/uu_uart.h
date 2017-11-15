
#ifndef _GUUD_UU_UART_H_
#define _GUUD_UU_UART_H_

#include <base/component.h>
#include <base/exception.h>
#include <base/stdint.h>

namespace Guud {
    class Uart;
    class Invalid_device : Genode::Exception {};
};

class Guud::Uart
{
    public:
        Uart(Genode::Env &) {}

        virtual Genode::size_t tx(const char*) = 0;
};

#endif //_GUUD_UU_UART_H_
