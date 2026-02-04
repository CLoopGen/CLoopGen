#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int *dst;
extern int scale;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 64; i += 2) {
        dst[i] = src[i] * scale;
        if (i + 1 < 64) {
            dst[i + 1] = src[i + 1] * scale;
        }
    }
}
