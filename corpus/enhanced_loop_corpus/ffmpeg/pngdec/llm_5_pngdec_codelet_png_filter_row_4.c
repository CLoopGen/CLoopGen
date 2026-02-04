#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *last;
extern int size;
extern int bpp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < size; i++) {
        if (i >= bpp && ((dst[i - bpp] + last[i]) & 1)) {
            dst[i] = ((dst[i - bpp] + last[i] + src[i] + 1) >> 1) & 255;
        } else {
            dst[i] = (((((dst[i - bpp]) + (last[i])) >> 1) + (src[i])) & 255);
        }
    }
}
