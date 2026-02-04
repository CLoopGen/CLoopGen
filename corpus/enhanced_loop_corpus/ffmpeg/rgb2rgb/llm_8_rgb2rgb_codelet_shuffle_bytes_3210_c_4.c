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
    for (i = 0; i < src_size; i += 8) {
        dst[i + 0] = src[i + 7];
        dst[i + 1] = src[i + 6];
        dst[i + 2] = src[i + 5];
        dst[i + 3] = src[i + 4];
        dst[i + 4] = src[i + 3];
        dst[i + 5] = src[i + 2];
        dst[i + 6] = src[i + 1];
        dst[i + 7] = src[i + 0];
    }
}
