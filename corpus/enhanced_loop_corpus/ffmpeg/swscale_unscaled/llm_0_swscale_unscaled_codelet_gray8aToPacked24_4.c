#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int num_pixels;
extern  uint8_t *palette;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < num_pixels; i++) {
    int index = src[i << 1] * 4;
    for (j = 0; j < 3; j++) {
        dst[j] = palette[index + j];
    }
    dst += 3;
}
}
