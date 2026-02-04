#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride simulation
    // Simulate larger stride by stepping through indices with a fixed step
    ptrdiff_t effective_stride = stride ? stride : 1; // avoid division by zero
    uint8_t *base = src - effective_stride;
    int indices[4] = {0, 2, 1, 3}; // shuffled access order to alter pattern

    for (i = 0; i < 4; i++) {
        int idx = indices[i];
        dc0 += base[idx];
        dc1 += base[4 + idx];
    }
}
