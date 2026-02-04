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
    int j;
    for (i = 0; i < num_pixels * 2; i += 2) {
        j = i / 2;
        dst[3 * j + 0] = src[4 * j + 2];
        dst[3 * j + 1] = src[4 * j + 1];
        dst[3 * j + 2] = src[4 * j + 0];
    }
}
