
#ifndef _GUUD_UU_UART_H_
#define _GUUD_UU_UART_H_

#include <base/component.h>
#include <base/exception.h>
#include <base/stdint.h>
#include <base/heap.h>
#include <base/allocator_avl.h>

#include <usb/usb.h>

namespace Guud {
    class Uart;
    class Invalid_device : Genode::Exception {};
};

class Guud::Uart
{
    private:
        Genode::Signal_context_capability _sigc;
        Genode::Signal_handler<Guud::Uart> _sigh;
        Genode::Heap &_heap;
        Genode::Allocator_avl _alloc;
        
        Usb::Connection _usb;
        Usb::Device _device;

        void handle_state_change();

    public:
        Uart(Genode::Env &, Genode::Heap &, Genode::Signal_context_capability);
        
        virtual Genode::size_t tx(const char*) = 0;
};

#endif //_GUUD_UU_UART_H_
