
#ifndef _GUUD_CP210X_H_
#define _GUUD_CP210X_H_

#include <uu_uart.h>

namespace Guud {
    class Cp210x;
};

class Guud::Cp210x : public Guud::Uart
{
    public:
        Cp210x(Genode::Env &);
        
        Genode::size_t tx(const char*) override;
};

#endif //_GUUD_CP210X_H_
