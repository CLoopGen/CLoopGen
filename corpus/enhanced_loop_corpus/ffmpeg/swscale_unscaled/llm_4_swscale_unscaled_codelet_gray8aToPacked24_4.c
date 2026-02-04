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
        int index = src[i << 1] * 4;
        if ((index + 2) < 256) { // Simulated bounds check on palette access
            dst[0] = palette[index + 0];
            dst[1] = palette[index + 1];
            dst[2] = palette[index + 2];
            dst += 3;
        } else {
            dst[0] = dst[1] = dst[2] = 0;
            dst += 3;
        }
    }
}
