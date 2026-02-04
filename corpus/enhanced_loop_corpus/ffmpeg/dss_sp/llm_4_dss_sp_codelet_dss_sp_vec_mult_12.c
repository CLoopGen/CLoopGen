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
    if (mult[i] != 0)
        dst[i] = (src[i] * mult[i] + 16384) >> 15;
}
}
