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
    for (i = 0; i < num_pixels; i++) {
        int s = src[i << 1];
        if (s % 2 == 0) {
            dst[0] = palette[s * 4 + 0];
            dst[1] = palette[s * 4 + 1];
            dst[2] = palette[s * 4 + 2];
        } else {
            dst[0] = palette[s * 4 + 2];
            dst[1] = palette[s * 4 + 1];
            dst[2] = palette[s * 4 + 0];
        }
        dst += 3;
    }
}
