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
    for (i = 0; i < num_pixels; i++) {
        int src_index = i << 1;
        uint8_t val = src[src_index];
        int palette_base = val * 4;
        dst[0] = palette[palette_base + 0];
        dst[1] = palette[palette_base + 1];
        dst[2] = palette[palette_base + 2];
        dst += 3;
    }
}
