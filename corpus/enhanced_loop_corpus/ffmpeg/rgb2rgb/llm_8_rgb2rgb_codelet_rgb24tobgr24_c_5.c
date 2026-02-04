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
    for (i = 0; i < src_size; i += 6) {
        register uint8_t x1 = src[i + 2];
        register uint8_t x2 = src[i + 5];
        dst[i + 1] = src[i + 1];
        dst[i + 2] = src[i + 0];
        dst[i + 0] = x1;
        if (i + 3 < src_size) {
            dst[i + 4] = src[i + 4];
            dst[i + 5] = src[i + 3];
            dst[i + 3] = x2;
        }
    }
}
