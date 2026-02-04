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
    for (i = 0; i < num_pixels; i += 2) {
        ((uint32_t *)dst)[i] = ((const uint32_t *)palette)[src[i]];
        if (i + 1 < num_pixels) {
            ((uint32_t *)dst)[i + 1] = ((const uint32_t *)palette)[src[i + 1]];
        }
    }
}
