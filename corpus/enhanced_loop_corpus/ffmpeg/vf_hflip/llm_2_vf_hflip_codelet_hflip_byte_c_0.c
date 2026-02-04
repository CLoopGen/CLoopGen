#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int w;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (forward on dst, backward on src)
    for (j = 0; j < w; j += 2) {
        if (j < w) dst[j] = src[-j];
        if (j + 1 < w) dst[j + 1] = src[-(j + 1)];
    }
}
