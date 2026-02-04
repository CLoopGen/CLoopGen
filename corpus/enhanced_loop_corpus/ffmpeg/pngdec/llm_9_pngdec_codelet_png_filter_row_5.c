#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int bpp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int factor = 3;
    for (i = 0; i < bpp; i++) {
        dst[i] = (src[i] * factor) + (src[i] / (factor + 1)) - (src[i] % factor);
    }
}
