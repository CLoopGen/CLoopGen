#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned int uint32;

extern int32 n_el;
extern int32 i;
extern uint32 *buf32;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_el; i++) {
        uint32 temp = *(buf32 + i);
        uint32 result = 0;

        result |= (temp >> 24) & 255;
        result |= (temp >> 8) & 65280;
        result |= (temp << 8) & 16711680;
        result |= (temp << 24) & 4278190080U;

        *(buf32 + i) = result;
    }
}
