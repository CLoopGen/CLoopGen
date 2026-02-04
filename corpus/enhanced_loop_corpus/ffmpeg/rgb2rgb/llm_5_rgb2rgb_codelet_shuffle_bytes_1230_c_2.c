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
for (i = 0; i < src_size; i += 4) {
    int offset = i;
    if (offset % 8 == 0) {
        dst[offset + 0] = src[offset + 1];
        dst[offset + 1] = src[offset + 2];
        dst[offset + 2] = src[offset + 3];
        dst[offset + 3] = src[offset + 0];
    } else {
        dst[offset + 0] = src[offset + 0];
        dst[offset + 1] = src[offset + 1];
        dst[offset + 2] = src[offset + 2];
        dst[offset + 3] = src[offset + 3];
    }
}
}
