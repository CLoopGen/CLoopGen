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
    uint32_t *dst32 = (uint32_t *)dst;
    const uint32_t *palette32 = (const uint32_t *)palette;
    for (j = 0; j < num_pixels; j += 2) {
        int idx1 = j << 1;
        int idx2 = idx1 + 2;
        if (j < num_pixels) {
            dst32[j] = palette32[src[idx1]] | src[idx1 + 1];
        }
        if (j + 1 < num_pixels) {
            dst32[j + 1] = palette32[src[idx2]] | src[idx2 + 1];
        }
    }
}
