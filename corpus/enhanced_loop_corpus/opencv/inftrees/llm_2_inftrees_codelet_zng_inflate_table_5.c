#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern uint16_t count[16];
extern uint16_t offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (unrolling-like pattern)
    // We process two iterations at once, accessing elements with a step
    for (len = 1; len < 14; len += 2) {
        offs[len + 1] = offs[len] + count[len];
        offs[len + 2] = offs[len + 1] + count[len + 1];
    }
    // Handle remaining iteration if needed (when len == 14)
    if (len == 14) {
        offs[len + 1] = offs[len] + count[len];
    }
}
