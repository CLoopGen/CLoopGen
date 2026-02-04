#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *dst;
extern int32_t *src0;
extern int32_t *src1;
extern ptrdiff_t len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increasing stride
    // Access elements using a fixed stride of 4, skipping over intermediate values
    // This changes temporal and spatial locality, simulating strided cache behavior.
    ptrdiff_t stride = 4;
    ptrdiff_t n = len / stride;  // Adjust effective length to avoid out-of-bounds
    for (i = 0; i < n; i++) {
        ptrdiff_t idx = i * stride;
        *dst++ = src1[idx];
        *dst++ = src0[idx + 1];  // Slight offset to maintain variation
    }
}
