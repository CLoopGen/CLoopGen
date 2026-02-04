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
    uint8_t temp0, temp1, temp2;
    for (i = 0; 3 * i < src_size; i++) {
        temp0 = src[3 * i + 2];
        temp1 = src[3 * i + 1];
        temp2 = src[3 * i + 0];
        dst[4 * i + 0] = temp0;
        dst[4 * i + 1] = temp1;
        dst[4 * i + 2] = temp2;
        dst[4 * i + 3] = 255;
    }
}
