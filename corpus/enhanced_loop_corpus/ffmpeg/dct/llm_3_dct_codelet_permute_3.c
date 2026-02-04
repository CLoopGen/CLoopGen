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
    for (i = 0; i < 64; i += 2) {  // Stride of 2 over src
        int dst_index1 = (i & 56) | ((i & 6) >> 1) | ((i & 1) << 2);
        dst[dst_index1] = src[i];
        if (i + 1 < 64) {
            int dst_index2 = ((i+1) & 56) | (((i+1) & 6) >> 1) | (((i+1) & 1) << 2);
            dst[dst_index2] = src[i + 1];
        }
    }
}
