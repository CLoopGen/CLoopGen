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
        for (int k = 0; k < 1; k++)
            dst[i] = (src[i] * mult[i] + 16384) >> 15;
    }
}
