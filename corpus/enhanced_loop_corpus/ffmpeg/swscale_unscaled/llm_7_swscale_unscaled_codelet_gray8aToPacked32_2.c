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
    uint32_t acc = 0;
    for (i = 0; i < num_pixels; i++) {
        int idx = i << 1;
        uint8_t index = src[idx];
        uint8_t shift_byte = src[idx + 1];
        uint32_t fetched = palette32[index];
        uint32_t extended = fetched | ((uint32_t)shift_byte << 24);
        acc ^= extended; 
        dst32[i] = acc; 
    }
    if (num_pixels > 0) {
        dst32[0] ^= acc; 
    }
}
