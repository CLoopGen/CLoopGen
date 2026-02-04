#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern int bpp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (; i < size; i += step) {
        if (i + 1 < size) {
            dst[i]     = dst[i - bpp] + src[i];
            dst[i + 1] = dst[i + 1 - bpp] + src[i + 1];
        } else {
            dst[i] = dst[i - bpp] + src[i];
        }
    }
}
