#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t v[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element, unrolled-like pattern)
    // We adjust the upper bound to ensure we don't go out of bounds with stride
    for (i = 0; i < 16 - 4; i += 2)
        v[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
}
