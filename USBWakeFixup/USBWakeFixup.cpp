//
//  USBWakeFixup.cpp
//  USBWakeFixup
//
//  Copyright © 2019 osy86. All rights reserved.
//

#include "USBWakeFixup.hpp"
#include <IOKit/IOLib.h>
#include <IOKit/acpi/IOACPIPlatformDevice.h>

#define super IOService

OSDefineMetaClassAndStructors(USBWakeFixup, IOService);

IOService *USBWakeFixup::probe(IOService *provider, SInt32 *score) {
    IOACPIPlatformDevice *acpiDevice = OSDynamicCast(IOACPIPlatformDevice, getProvider());
    
    if (!acpiDevice) {
        IOLog("invalid parent, need IOACPIPlatformDevice\n");
        return NULL;
    }
    IOLog("adding acpi-wake-type property\n");
    acpiDevice->setProperty("acpi-wake-type", 0x1, 32);
    acpiDevice->setSystemWakeCapabilityEnable(true);
    return NULL;
}
