#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern unsigned int mask;
extern ptrdiff_t w;
extern unsigned int acc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    // Access every second element in both src and dst arrays
    ptrdiff_t stride = 2;
    for (; i < w; i += stride) {
        acc += src[i];
        dst[i] = acc & mask;
        acc &= mask;
    }
}
