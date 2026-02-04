#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    const ptrdiff_t s = stride;
    const uint8_t *srcp = src;
    uint8_t *dstp = dst;
    dstp[0] = ((dstp[0] + (((A * srcp[0] + B * srcp[1] + C * srcp[s+0] + D * srcp[s+1] + 32) >> 6) + 1)) >> 1);
    dstp[1] = ((dstp[1] + (((A * srcp[1] + B * srcp[2] + C * srcp[s+1] + D * srcp[s+2] + 32) >> 6) + 1)) >> 1);
    dstp[2] = ((dstp[2] + (((A * srcp[2] + B * srcp[3] + C * srcp[s+2] + D * srcp[s+3] + 32) >> 6) + 1)) >> 1);
    dstp[3] = ((dstp[3] + (((A * srcp[3] + B * srcp[4] + C * srcp[s+3] + D * srcp[s+4] + 32) >> 6) + 1)) >> 1);
    dstp[4] = ((dstp[4] + (((A * srcp[4] + B * srcp[5] + C * srcp[s+4] + D * srcp[s+5] + 32) >> 6) + 1)) >> 1);
    dstp[5] = ((dstp[5] + (((A * srcp[5] + B * srcp[6] + C * srcp[s+5] + D * srcp[s+6] + 32) >> 6) + 1)) >> 1);
    dstp[6] = ((dstp[6] + (((A * srcp[6] + B * srcp[7] + C * srcp[s+6] + D * srcp[s+7] + 32) >> 6) + 1)) >> 1);
    dstp[7] = ((dstp[7] + (((A * srcp[7] + B * srcp[8] + C * srcp[s+7] + D * srcp[s+8] + 32) >> 6) + 1)) >> 1);
    dst += stride;
    src += stride;
}
}
