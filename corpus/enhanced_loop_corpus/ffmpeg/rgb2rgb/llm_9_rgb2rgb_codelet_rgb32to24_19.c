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
    for (i = 0; i < num_pixels; i++) {
        uint8_t temp1 = src[4 * i + 2];
        uint8_t temp2 = src[4 * i + 1];
        uint8_t temp3 = src[4 * i + 0];
        dst[3 * i + 0] = temp1;
        dst[3 * i + 1] = temp2;
        dst[3 * i + 2] = temp3;
    }
}
