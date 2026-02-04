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
    for (i = 0; i < num_pixels * 2; i += 2) {
        int idx = i >> 1;
        if (idx < num_pixels) {
            uint8_t low = src[i];
            uint8_t high = src[i + 1];
            ((uint32_t *)dst)[idx] = ((const uint32_t *)palette)[low] | high;
        }
    }
}
