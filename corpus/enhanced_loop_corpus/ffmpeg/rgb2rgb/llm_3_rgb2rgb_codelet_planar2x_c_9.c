#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int srcWidth;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – process every 2nd element in source (downsampled pattern)
    // This changes access pattern to strided, reducing effective width accordingly
    int stride = 2;
    int effectiveWidth = (srcWidth - 1) / stride;
    for (x = 0; x < effectiveWidth; x++) {
        int src_idx = x * stride;
        int dst_idx = 2 * x;
        dst[dst_idx + 1] = (3 * src[src_idx] + src[src_idx + 1]) >> 2;
        dst[dst_idx + 2] = (src[src_idx] + 3 * src[src_idx + 1]) >> 2;
    }
}
