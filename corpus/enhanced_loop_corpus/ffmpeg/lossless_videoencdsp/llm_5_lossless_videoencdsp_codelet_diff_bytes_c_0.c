#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern intptr_t w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < w; i++) {
        if (src1[i] >= src2[i]) {
            dst[i] = src1[i] - src2[i];
        } else {
            dst[i] = 0;
        }
    }
}
