#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t keys[12];
extern uint32_t v;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increasing index and stride of 2 (modulo array size to stay in bounds)
    v = 1; // reset v if needed for meaningful computation
    for (i = 0; i < 4; i++) {
        int idx = (i * 2) % 12; // Strided access: indices 0, 2, 4, 6
        v *= keys[idx];
        v = (v >> 16) | (v << 16);
    }
}
