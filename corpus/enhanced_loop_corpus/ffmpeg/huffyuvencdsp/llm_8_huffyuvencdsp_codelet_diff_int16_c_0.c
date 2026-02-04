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
    for (; i < w; i += 2) {
        if (i + 1 < w) {
            dst[i]     = (src1[i] - src2[i]) & mask;
            dst[i + 1] = (src1[i + 1] - src2[i + 1]) & mask;
        } else {
            dst[i] = (src1[i] - src2[i]) & mask;
        }
    }
}
