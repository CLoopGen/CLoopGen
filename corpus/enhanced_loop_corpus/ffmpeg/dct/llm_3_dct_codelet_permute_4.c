#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access on src with fixed stride, writing to permuted dst indices
    for (i = 0; i < 64; i += 2) { // Stride of 2 on loop index
        dst[(i & 36) | ((i & 3) << 3) | ((i >> 3) & 3)] = src[i];
    }
    // Handle remaining elements if any (ensuring full coverage)
    for (i = 1; i < 64; i += 2) {
        dst[(i & 36) | ((i & 3) << 3) | ((i >> 3) & 3)] = src[i];
    }
}
