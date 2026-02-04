#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *src;
extern int32_t *dst;
extern  int16_t *mult;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 2; i < 30; i += 2)
        dst[i/2] = (src[i] * mult[i] + 16384) >> 15;
}
