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
    for (j = bpp; j < size; j += 2) {
        dst[j] = src[j] - ((src[j - bpp] + top[j]) >> 1);
        if (j + 1 < size) {
            dst[j + 1] = src[j + 1] - ((src[j + 1 - bpp] + top[j + 1]) >> 1);
        }
    }
}
