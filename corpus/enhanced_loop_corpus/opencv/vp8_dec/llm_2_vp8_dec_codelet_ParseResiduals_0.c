#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int i;
extern  int dc0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride of 4
    for (i = 0; i < 16 * 16; i += 64) {
        dst[i + 0] = dc0;
        dst[i + 16] = dc0;
        dst[i + 32] = dc0;
        dst[i + 48] = dc0;
    }
}
