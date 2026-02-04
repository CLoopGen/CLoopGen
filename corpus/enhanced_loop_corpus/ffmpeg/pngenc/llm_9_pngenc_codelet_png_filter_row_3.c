#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *top;
extern int bpp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < bpp; i++) {
        int temp_top = top[i] >> 1;
        int diff = src[i] - temp_top;
        dst[i] = (diff < 0) ? 0 : (diff > 255) ? 255 : diff;
    }
}
