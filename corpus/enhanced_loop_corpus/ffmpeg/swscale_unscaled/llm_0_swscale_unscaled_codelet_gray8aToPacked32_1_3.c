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
    for (j = 0; j < num_pixels; j += 8) {
        for (i = j; i < j + 8 && i < num_pixels; i++) {
            ((uint32_t *)dst)[i] = ((const uint32_t *)palette)[src[i << 1]] | src[(i << 1) + 1];
        }
    }
}
