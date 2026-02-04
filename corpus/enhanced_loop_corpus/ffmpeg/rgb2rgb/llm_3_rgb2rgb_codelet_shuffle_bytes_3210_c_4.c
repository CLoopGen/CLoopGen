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
        int j = src_size - 1 - i;
        dst[i + 0] = src[j - 0];
        dst[i + 1] = src[j - 1];
        dst[i + 2] = src[j - 2];
        dst[i + 3] = src[j - 3];
    }
}
