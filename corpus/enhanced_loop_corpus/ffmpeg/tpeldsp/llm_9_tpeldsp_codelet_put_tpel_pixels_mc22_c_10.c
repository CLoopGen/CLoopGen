#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        int val = src[j] + src[j + stride];
        val = (val + (val >> 1) + src[j + 1]) >> 1;
        dst[j] = (val * 4369) >> 14; // Approximate multiplication by ~0.25
    }
    src += stride;
    dst += stride;
}
}
