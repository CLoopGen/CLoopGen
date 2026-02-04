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
        if (i % 2 == 0) {
            dst[3 * i + 0] = src[4 * i + 2];
            dst[3 * i + 1] = src[4 * i + 1];
            dst[3 * i + 2] = src[4 * i + 0];
        } else {
            dst[3 * i + 0] = 0;
            dst[3 * i + 1] = 0;
            dst[3 * i + 2] = 0;
        }
    }
}
