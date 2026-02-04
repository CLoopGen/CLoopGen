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
    if (i >= size) return;
    for (; i < size; i++) {
        int pred = (i >= bpp) ? src[i - bpp] : 0;
        dst[i] = src[i] - ((pred + top[i]) >> 1);
    }
}
