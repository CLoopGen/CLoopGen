#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t v[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step of 2 (unrolled-like pattern)
    // Access every second element, reducing total iterations but maintaining alignment
    for (i = 0; i < 16 - 4; i += 2) {
        v[i]     = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
        v[i + 1] = (top[i + 1] + top[i + 2] * 2 + top[i + 3] + 2) >> 2;
    }
    // Handle remaining elements if any (tail handling for odd index)
    if (i == 14) {
        v[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    }
}
