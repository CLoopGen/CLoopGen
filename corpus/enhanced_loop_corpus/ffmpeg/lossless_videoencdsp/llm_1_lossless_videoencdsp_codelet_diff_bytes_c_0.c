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
    for (long j = 0; j < w; j += 2) {
        dst[j + 0] = src1[j + 0] - src2[j + 0];
        if (j + 1 < w) {
            dst[j + 1] = src1[j + 1] - src2[j + 1];
        }
    }
}
