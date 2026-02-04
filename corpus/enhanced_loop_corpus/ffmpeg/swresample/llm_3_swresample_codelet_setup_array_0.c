#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out[32];
extern uint8_t *in;
extern int i;
extern int plane_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - reverse order with stride of 2
    int stride = 2;
    int limit = (32 + stride - 1) / stride * stride; // Round up to multiple of stride
    for (i = 0; i < limit; i += stride) {
        int idx1 = 31 - i; // descending index
        int idx2 = 31 - i - 1;
        if (idx1 >= 0) out[idx1] = in + idx1 * plane_size;
        if (idx2 >= 0 && idx2 >= 0) out[idx2] = in + idx2 * plane_size;
    }
}
