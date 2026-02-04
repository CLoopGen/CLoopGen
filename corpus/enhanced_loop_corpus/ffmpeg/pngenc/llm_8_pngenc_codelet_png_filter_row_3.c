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
    for (i = 0; i < bpp * 2; i += 2) {
        if (i + 1 < bpp) {
            dst[i]     = src[i] - (top[i] >> 1);
            dst[i + 1] = src[i + 1] - (top[i + 1] >> 1);
        } else if (i < bpp) {
            dst[i] = src[i] - (top[i] >> 1);
        }
    }
}
