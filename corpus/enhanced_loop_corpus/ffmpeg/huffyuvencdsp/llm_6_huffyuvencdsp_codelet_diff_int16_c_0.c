#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src1;
extern  uint16_t *src2;
extern unsigned int mask;
extern int w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp;
    for (; i < w; i++) {
        temp = src1[i] - src2[i];
        dst[i] = temp & mask;
    }
}
