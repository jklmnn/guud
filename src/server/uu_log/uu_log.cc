
#include <uu_log.h>

#include <uu_uart.h>

Genode::size_t Guud::Log_component::write(String const &str)
{
    if(!str.valid_string()){
        Genode::error("invalid string");
        return 0;
    }

    const char *line = str.string();
    
    _uart.tx(line);

    return Genode::strlen(line);
}

Guud::Log_component *Guud::Log_root::_create_session(const char *args)
{
    char label[64];

    Genode::Arg label_arg = Genode::Arg_string::find_arg(args, "label");
    label_arg.string(label, sizeof(label), "");

    return new (md_alloc()) Guud::Log_component(label, _env, _uart);
}
