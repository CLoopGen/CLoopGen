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
    for (j = 0; j < num_pixels; j += 2) {
        if (j + 1 < num_pixels) {
            ((uint32_t *)dst)[j]     = ((const uint32_t *)palette)[src[j]];
            ((uint32_t *)dst)[j + 1] = ((const uint32_t *)palette)[src[j + 1]];
        } else {
            ((uint32_t *)dst)[j] = ((const uint32_t *)palette)[src[j]];
        }
    }
}
