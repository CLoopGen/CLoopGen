#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int height;
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by factor of 2
    // This variant assumes height is even and accesses two elements per iteration for better spatial locality
    int i;
    uint8_t *d = dst;
    uint8_t *s = src;
    ptrdiff_t ds = stride_dst;
    ptrdiff_t ss = stride_src;
    for (i = 0; i < height; i += 2) {
        *d = *s;
        *(d + ds) = *(s + ss);
        d += 2 * ds;
        s += 2 * ss;
    }
}
