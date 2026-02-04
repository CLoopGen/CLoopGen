#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t buf[1999];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < sizeof(buf); i += 2) {
        buf[i] = i + i * i;
        if (i + 1 < sizeof(buf)) {
            buf[i + 1] = (i + 1) + (i + 1) * (i + 1);
        }
    }
}
