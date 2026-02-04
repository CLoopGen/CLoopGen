#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int i;
extern int num_pixels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp_r, temp_g, temp_b;
    for (i = 0; i < num_pixels; i++) {
        temp_b = src[4 * i + 0];
        temp_g = src[4 * i + 1];
        temp_r = src[4 * i + 2];
        dst[3 * i + 0] = temp_r;
        dst[3 * i + 1] = temp_g;
        dst[3 * i + 2] = temp_b;
    }
}
