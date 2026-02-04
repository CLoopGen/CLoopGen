#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < 64; i += 2) {
        dst[i] -= 512;
        if (i + 1 < 64) {
            dst[i + 1] -= 512;
        }
    }
}
