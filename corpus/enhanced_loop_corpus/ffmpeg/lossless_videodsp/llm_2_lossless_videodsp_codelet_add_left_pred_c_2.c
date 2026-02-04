#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t w;
extern int acc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride of 2 (sequential read/write)
    for (i = 0; i < w - 1; i += 2) {
        acc += src[i];
        dst[i] = acc;
        acc += src[i + 1];
        dst[i + 1] = acc;
    }
}
