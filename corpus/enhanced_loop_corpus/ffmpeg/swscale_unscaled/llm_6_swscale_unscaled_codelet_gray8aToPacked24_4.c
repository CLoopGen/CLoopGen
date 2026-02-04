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
    const uint8_t *local_src = src;
    const uint8_t *local_palette = palette;
    int i_local = 0;
    for (i = 0; i < num_pixels; i++) {
        int index = local_src[i_local << 1] * 4;
        local_dst[0] = local_palette[index + 0];
        local_dst[1] = local_palette[index + 1];
        local_dst[2] = local_palette[index + 2];
        local_dst += 3;
        i_local++;
    }
    dst = local_dst;
}
