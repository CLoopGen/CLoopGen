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
    dst[0] = src[0] * scale;
    for (i = 1; i < 64; i++) {
        dst[i] = src[i] * scale + dst[i-1] / 256;
    }
}
