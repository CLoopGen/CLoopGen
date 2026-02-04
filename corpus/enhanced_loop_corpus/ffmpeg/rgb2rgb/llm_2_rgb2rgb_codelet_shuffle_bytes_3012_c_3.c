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
        int idx = i;
        dst[idx] = src[idx + 3];
        dst[idx + 1] = src[idx];
        dst[idx + 2] = src[idx + 1];
        dst[idx + 3] = src[idx + 2];
    }
}
