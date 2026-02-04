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
    int j;
    for (i = 0; 3 * i < src_size; i++) {
        j = 4 * i;
        dst[j + 0] = src[3 * i + 2];
        dst[j + 1] = src[3 * i + 1];
        dst[j + 2] = src[3 * i + 0];
        dst[j + 3] = 255;
    }
}
