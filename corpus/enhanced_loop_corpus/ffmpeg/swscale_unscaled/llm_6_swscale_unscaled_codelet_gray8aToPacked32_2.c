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
    uint32_t *dst32 = (uint32_t *)dst;
    const uint32_t *palette32 = (const uint32_t *)palette;
    for (i = 0; i < num_pixels; i++) {
        int idx = i << 1;
        uint8_t src_low = src[idx];
        uint8_t src_high = src[idx + 1];
        uint32_t palette_val = palette32[src_low];
        dst32[i] = palette_val | ((uint32_t)src_high << 24);
    }
}
