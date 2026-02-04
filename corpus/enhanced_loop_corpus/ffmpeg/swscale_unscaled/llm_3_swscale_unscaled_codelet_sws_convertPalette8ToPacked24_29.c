#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int num_pixels;
extern  uint8_t *palette;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every second pixel first, then the others (interleaved pattern)
    int i;
    // First pass: even indices
    for (i = 0; i < num_pixels; i += 2) {
        int src_idx = src[i] * 4;
        dst[0] = palette[src_idx + 0];
        dst[1] = palette[src_idx + 1];
        dst[2] = palette[src_idx + 2];
        dst += 3;
    }
    // Second pass: odd indices
    for (i = 1; i < num_pixels; i += 2) {
        int src_idx = src[i] * 4;
        dst[0] = palette[src_idx + 0];
        dst[1] = palette[src_idx + 1];
        dst[2] = palette[src_idx + 2];
        dst += 3;
    }
}
