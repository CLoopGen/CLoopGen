#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled accumulation
    // Instead of strided access within each iteration, process two consecutive elements
    // in a coalesced manner to improve cache locality and enable potential vectorization.
    for (i = 0; i < h; i++) {
        ptrdiff_t base_src = i * stride;
        ptrdiff_t base_dst = i * stride;
        uint8_t s0 = src[base_src];
        uint8_t s1 = src[base_src + 1];
        uint8_t s2 = src[base_src + step];
        uint8_t s3 = src[base_src + step + 1];

        dst[base_dst]     = (((A * s0 + E * s2) + 32) >> 6);
        dst[base_dst + 1] = (((A * s1 + E * s3) + 32) >> 6);
    }
}
