#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int threshold;
extern int w;
extern  uint16_t *src;
extern  uint16_t *ref;
extern uint16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Processes elements at even indices first, then odd indices in a second pass
    int stride = 2;
    int offset;
    for (offset = 0; offset < stride; offset++) {
        for (int x = offset; x < w; x += stride) {
            dst[x] = ((src[x] - ref[x]) >= 0 ? (src[x] - ref[x]) : (-(src[x] - ref[x]))) <= threshold ? src[x] : ref[x];
        }
    }
}
