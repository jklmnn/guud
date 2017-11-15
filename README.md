# Genode Usb Uart Debug (GUUD)

## What is GUUD

Genode Usb Uart Debug is a library intended to provide fast debugging access to a wide range of devices. Many modern consumer devices come without any (useful) debugging interfaces but most have some kind of USB access. Bootstrapping driver development on these devices can be hard without any initial debug/log output. On [Genode](https://github.com/genodelabs/genode) USB support is available for a wide range of devices (at least on x86) which prompts the use of USB to get log information.

This library aims to implement a range of USB to Uart converter drivers for the use with Genodes LOG session. The goal is a fast access to new devices and new converters. Because of this driver implementations in this repositoriy will be limited to the functionality that is required to send log information from the target device.
