#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int coordmap[64];
extern  int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step of 8, writing to every 8th element in reverse order
    for (i = 0; i < 64; i += 8) {
        int idx = 63 - i;  // Reverse logical index
        coordmap[idx] = (idx & 7) + (idx >> 3) * stride;
    }
    // Fill remaining elements with sequential forward pass for completeness
    for (i = 7; i > 0; i--) {
        int j = 63 - i;
        coordmap[j] = (j & 7) + (j >> 3) * stride;
    }
}
