#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 4
    size_t n = sizeof(buf);
    for (i = 0; i < n; i += 4) {
        buf[i] = 255 & i;
        if (i + 1 < n) buf[i + 1] = 255 & (i + 1);
        if (i + 2 < n) buf[i + 2] = 255 & (i + 2);
        if (i + 3 < n) buf[i + 3] = 255 & (i + 3);
    }
}
