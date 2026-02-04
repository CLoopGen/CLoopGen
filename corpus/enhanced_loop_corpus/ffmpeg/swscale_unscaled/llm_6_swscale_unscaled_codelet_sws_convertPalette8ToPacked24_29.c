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
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    const uint8_t *local_palette = palette;
    int local_num_pixels = num_pixels;
    for (i = 0; i < local_num_pixels; i++) {
        uint8_t index = local_src[i];
        local_dst[0] = local_palette[index * 4 + 0];
        local_dst[1] = local_palette[index * 4 + 1];
        local_dst[2] = local_palette[index * 4 + 2];
        local_dst += 3;
    }
    dst = local_dst;
}
