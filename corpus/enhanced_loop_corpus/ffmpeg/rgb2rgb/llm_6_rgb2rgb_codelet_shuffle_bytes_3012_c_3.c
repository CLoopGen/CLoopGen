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
    uint8_t temp1, temp2, temp3, temp4;
    for (i = 0; i < src_size; i += 4) {
        temp1 = src[i + 3];
        temp2 = src[i + 0];
        temp3 = src[i + 1];
        temp4 = src[i + 2];
        dst[i + 0] = temp1;
        dst[i + 1] = temp2;
        dst[i + 2] = temp3;
        dst[i + 3] = temp4;
    }
}
