#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    register uint8_t x;
    for (i = 0; i < src_size; i += 3) {
        x = src[i + 2];
        dst[i + 0] = x;
        dst[i + 1] = src[i + 1];
        dst[i + 2] = src[i + 0];
    }
}
