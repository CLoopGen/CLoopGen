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
    int i_val;
    uint32_t temp_value = 0;
    for (i = 0; i < num_pixels; i++) {
        i_val = i << 1;
        temp_value = palette32[src8[i_val]] | src8[i_val + 1];
        dst32[i] = temp_value;
    }
}
