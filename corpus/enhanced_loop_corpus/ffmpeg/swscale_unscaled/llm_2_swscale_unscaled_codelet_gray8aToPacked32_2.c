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
    for (j = 0; j < num_pixels; j++) {
        int idx = j << 1;
        ((uint32_t *)dst)[j] = ((const uint32_t *)palette)[src[idx]] | ((uint32_t)src[idx + 1] << 24);
    }
}
