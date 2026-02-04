#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *dst;
extern  uint32_t *src;
extern int stride;
extern int height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < height; i++) {
    uint32_t temp;
    for (int j = 0; j < stride >> 2; j++) {
        temp = src[j] >> 3;
        dst[j] = ((temp + (1061109567 & dst[j])) << 3) & 4244438268U;
    }
    dst += stride >> 2;
    src += stride >> 2;
}
}
