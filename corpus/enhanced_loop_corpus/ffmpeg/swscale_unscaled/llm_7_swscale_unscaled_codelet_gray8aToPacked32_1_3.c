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
    uint8_t *src8 = src;
    for (i = 0; i < num_pixels; i++) {
        uint8_t index_low = src8[i << 1];
        uint8_t data_high = src8[(i << 1) + 1];
        dst32[i] = palette32[index_low];          
        dst32[i] |= data_high;                   
    }
}
