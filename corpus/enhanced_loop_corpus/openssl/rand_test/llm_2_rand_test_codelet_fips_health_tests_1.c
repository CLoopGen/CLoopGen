#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element, forward)
    for (i = 0; i < 20; i += 2)
        buf[i] = 255 & (i > 10 ? 200 : i);
}
