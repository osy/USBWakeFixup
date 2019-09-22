USBWakeFixup
============

On systems without a working Embedded Controller, waking up from a USB device 
might not wake up the display. A second key-press or mouse click is required 
to wake up the display. This extension is a workaround for that issue by 
creating a fake ACPI device with the right wakeup params.

## Shared GPE

If multiple devices share a single GPE, then they will ALL cause display 
wakeup with this workaround installed. This is an unfortunate side-effect. If 
you have a Ethernet controller with WoL enabled and it happens to be the same 
GPE as your USB controller, then WoL will now wake the display.

## Details

Check [here][1] for a more detailed technical writeup on how this works. You 
should only use this if injecting `acpi-wake-type` on XHCI does not work due 
to the Intel PCH bug. Please see [this issue][2] for more information.

## Installation

1. Build and install `SSDT-USBW.dsl` into your bootloader DSDT injection.
   You may need to modify it to point to your XHC device.
2. Install the kext.

[1]: https://osy.gitbook.io/hac-mini-guide/details/usb-fix
[2]: https://github.com/osy86/USBWakeFixup/issues/2
