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
    int outer_i;
    for (outer_i = i; outer_i < size; outer_i++) {
        i = outer_i;
        dst[i] = src[i] - ((src[i - bpp] + top[i]) >> 1);
    }
}
