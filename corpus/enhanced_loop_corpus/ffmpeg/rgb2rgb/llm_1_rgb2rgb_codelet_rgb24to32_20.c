#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; 3 * i + 2 < src_size; i++) {
    int offset = 3 * i;
    dst[4 * i + 0] = src[offset + 2];
    dst[4 * i + 1] = src[offset + 1];
    dst[4 * i + 2] = src[offset + 0];
    dst[4 * i + 3] = 255;
}
for (; 3 * i < src_size; i++) {
    int rem = src_size - 3 * i;
    dst[4 * i + 0] = (rem > 2) ? src[3 * i + 2] : 255;
    dst[4 * i + 1] = (rem > 1) ? src[3 * i + 1] : 255;
    dst[4 * i + 2] = src[3 * i + 0];
    dst[4 * i + 3] = 255;
}
}
