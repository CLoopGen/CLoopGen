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
if (num_pixels > 0) {
    for (i = 0; i < num_pixels; i++) {
        ((uint32_t *)dst)[i] = ((const uint32_t *)palette)[src[i]];
        i++; // Simulate partial unrolling by manually advancing
        if (i < num_pixels)
            ((uint32_t *)dst)[i] = ((const uint32_t *)palette)[src[i]];
    }
} else {
    for (i = 0; i < num_pixels; i++) {
        ((uint32_t *)dst)[i] = ((const uint32_t *)palette)[src[i]];
    }
}
}
