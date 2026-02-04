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
    // Variant 2: Consecutive reverse traversal from end to beginning
    for (; i > 0; ) {
        i--;
        dst[i] = src[i] - ((src[i - bpp] + top[i]) >> 1);
    }
}
