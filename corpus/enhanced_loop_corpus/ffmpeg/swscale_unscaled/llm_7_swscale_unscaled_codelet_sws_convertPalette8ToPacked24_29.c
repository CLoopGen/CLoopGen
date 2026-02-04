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
    uint8_t temp[3];
    for (i = 0; i < num_pixels; i++) {
        uint8_t val = src[i];
        temp[0] = palette[val * 4 + 0];
        temp[1] = palette[val * 4 + 1];
        temp[2] = palette[val * 4 + 2];
        dst[0] = temp[0];
        dst[1] = temp[1];
        dst[2] = temp[2];
        dst += 3;
    }
}
