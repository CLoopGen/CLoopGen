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
        int offset = src[i] << 2;  // Replace multiplication with bit shift
        dst[0] = palette[offset];
        dst[1] = palette[offset + 1];
        dst[2] = palette[offset + 2];
        // Remove pointer increment by 3 and use direct indexing
        dst = &dst[3];
    }
}
