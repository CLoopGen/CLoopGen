#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern uint8_t mask;
extern  uint8_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i += 2) {
        int shift1 = 7 - i;
        int shift2 = 3 - i;
        uint8_t mask1 = mask & (1 << shift1);
        uint8_t mask2 = mask & (1 << shift2);
        if (mask1 && (i < 4))
            dst[i] = src[i];
        if (mask2 && (i < 4))
            dst[width + i] = src[width + i];
    }
}
