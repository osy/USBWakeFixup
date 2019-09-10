//
//  USBWakeFixup.hpp
//  USBWakeFixup
//
//  Copyright © 2019 osy86. All rights reserved.
//

#ifndef USBWakeFixup_hpp
#define USBWakeFixup_hpp

#include <IOKit/IOService.h>

class USBWakeFixup : public IOService {
    OSDeclareDefaultStructors(USBWakeFixup);
public:
    virtual IOService *probe(IOService *provider, SInt32 *score) override;
};

#endif /* USBWakeFixup_hpp */
