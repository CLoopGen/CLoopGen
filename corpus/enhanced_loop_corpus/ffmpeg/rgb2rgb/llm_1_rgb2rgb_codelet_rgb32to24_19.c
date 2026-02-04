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
    int outer = num_pixels / 2;
    int remainder = num_pixels % 2;
    for (i = 0; i < outer; i++) {
        int idx = 2 * i;
        dst[3 * idx + 0] = src[4 * idx + 2];
        dst[3 * idx + 1] = src[4 * idx + 1];
        dst[3 * idx + 2] = src[4 * idx + 0];

        dst[3 * (idx + 1) + 0] = src[4 * (idx + 1) + 2];
        dst[3 * (idx + 1) + 1] = src[4 * (idx + 1) + 1];
        dst[3 * (idx + 1) + 2] = src[4 * (idx + 1) + 0];
    }
    // Handle remaining element if num_pixels is odd
    if (remainder) {
        dst[3 * (num_pixels - 1) + 0] = src[4 * (num_pixels - 1) + 2];
        dst[3 * (num_pixels - 1) + 1] = src[4 * (num_pixels - 1) + 1];
        dst[3 * (num_pixels - 1) + 2] = src[4 * (num_pixels - 1) + 0];
    }
}
