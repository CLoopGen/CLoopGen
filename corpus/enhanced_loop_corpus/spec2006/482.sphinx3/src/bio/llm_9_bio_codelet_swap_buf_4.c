#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned int uint32;

extern int32 n_el;
extern int32 i;
extern uint32 *buf32;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_el && i < 1024; i++) {
        uint32 val = *(buf32 + i);
        uint32 byte0 = (val >> 24) & 255;
        uint32 byte1 = (val >> 8) & 65280;
        uint32 byte2 = (val << 8) & 16711680;
        uint32 byte3 = (val << 24) & 4278190080U;
        *(buf32 + i) = byte0 | byte1 | byte2 | byte3;
    }
}
