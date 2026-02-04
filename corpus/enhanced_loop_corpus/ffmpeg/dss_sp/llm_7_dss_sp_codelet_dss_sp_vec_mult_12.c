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
    for (i = 1; i < 15; i++) {
        dst[i] = (src[i] * mult[i] + 16384) >> 15;
        dst[i+1] = (dst[i] + src[i]) >> 1; // Introduces WAW and RAW loop-carried dependency
    }
}
