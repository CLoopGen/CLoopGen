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
    long j;
    uint16_t temp0, temp1, temp2, temp3;
    for (i = 0; i + 3 < w; i += 4) {
        temp0 = (src1[i + 0] - src2[i + 0]) & mask;
        temp1 = (src1[i + 1] - src2[i + 1]) & mask;
        temp2 = (src1[i + 2] - src2[i + 2]) & mask;
        temp3 = (src1[i + 3] - src2[i + 3]) & mask;
        dst[i + 0] = temp0;
        dst[i + 1] = temp1;
        dst[i + 2] = temp2;
        dst[i + 3] = temp3;
    }
}
