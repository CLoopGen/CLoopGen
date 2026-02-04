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
    for (i = 0; i + 7 < w; i += 8) {
        dst[i + 0] = (src1[i + 0] - src2[i + 0]) & mask;
        dst[i + 1] = (src1[i + 1] - src2[i + 1]) & mask;
        dst[i + 2] = (src1[i + 2] - src2[i + 2]) & mask;
        dst[i + 3] = (src1[i + 3] - src2[i + 3]) & mask;
        dst[i + 4] = (src1[i + 4] - src2[i + 4]) & mask;
        dst[i + 5] = (src1[i + 5] - src2[i + 5]) & mask;
        dst[i + 6] = (src1[i + 6] - src2[i + 6]) & mask;
        dst[i + 7] = (src1[i + 7] - src2[i + 7]) & mask;
    }
}
