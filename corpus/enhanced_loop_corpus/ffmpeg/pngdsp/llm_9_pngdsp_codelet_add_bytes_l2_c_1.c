#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src1;
extern uint8_t *src2;
extern int w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long j;
    for (j = 0; j < w; j++) {
        dst[j] = src1[j] + src2[j] - src1[j] + src2[j] * 2;
    }
}
