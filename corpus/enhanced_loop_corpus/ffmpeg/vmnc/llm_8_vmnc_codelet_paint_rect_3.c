#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int w;
extern int h;
extern int color;
extern int stride;
extern int i;
extern int j;
extern uint16_t *dst2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < h; j++) {
    dst2 = (uint16_t *)dst;
    for (i = 0; i < w * 2; i += 2) {
        dst2[i] = color;
        dst2[i + 1] = color;
    }
    dst += stride;
}
}
