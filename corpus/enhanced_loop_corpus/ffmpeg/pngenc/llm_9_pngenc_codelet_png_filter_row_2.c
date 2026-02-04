#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *top;
extern int size;
extern int bpp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 2 * bpp; j < size; j++) {
        uint8_t pred = (src[j - bpp] + top[j] + src[j - 2*bpp] + top[j - bpp]) >> 2;
        dst[j] = src[j] - pred;
    }
}
