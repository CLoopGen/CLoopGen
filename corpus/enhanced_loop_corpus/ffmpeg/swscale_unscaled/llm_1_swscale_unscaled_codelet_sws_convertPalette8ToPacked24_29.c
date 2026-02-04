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
int chunk_size = 4;
int limit = num_pixels - (num_pixels % chunk_size);
for (i = 0; i < limit; i += chunk_size) {
    int j;
    for (j = 0; j < chunk_size; j++) {
        int idx = i + j;
        dst[0] = palette[src[idx] * 4 + 0];
        dst[1] = palette[src[idx] * 4 + 1];
        dst[2] = palette[src[idx] * 4 + 2];
        dst += 3;
    }
}
for (; i < num_pixels; i++) {
    dst[0] = palette[src[i] * 4 + 0];
    dst[1] = palette[src[i] * 4 + 1];
    dst[2] = palette[src[i] * 4 + 2];
    dst += 3;
}
}
