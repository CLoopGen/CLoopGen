#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Consecutive Memory Access (iterate backward)
    for (i = 19; ; i--) {
        buf[i] = 255 & (i > 10 ? 200 : i);
        if (i == 0) break;
    }
}
