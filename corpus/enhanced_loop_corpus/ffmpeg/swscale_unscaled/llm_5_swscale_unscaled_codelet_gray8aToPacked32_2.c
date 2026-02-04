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
        int skip = (src[i << 1] == 0);
        if (!skip) {
            ((uint32_t *)dst)[i] = ((const uint32_t *)palette)[src[i << 1]] | (src[(i << 1) + 1] << 24);
        } else {
            ((uint32_t *)dst)[i] = 0;
        }
    }
}
