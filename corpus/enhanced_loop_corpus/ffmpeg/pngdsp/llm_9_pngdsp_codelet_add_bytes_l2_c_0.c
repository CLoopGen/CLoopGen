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
long step = sizeof(long);
for (i = 0; i <= w - 4 * step; i += 4 * step) {
    long a0 = *(long *)(src1 + i);
    long a1 = *(long *)(src1 + i + step);
    long a2 = *(long *)(src1 + i + 2*step);
    long a3 = *(long *)(src1 + i + 3*step);
    long b0 = *(long *)(src2 + i);
    long b1 = *(long *)(src2 + i + step);
    long b2 = *(long *)(src2 + i + 2*step);
    long b3 = *(long *)(src2 + i + 3*step);
    long mask_127 = ~0UL / 255 * 127;
    long mask_128 = ~0UL / 255 * 128;
    *(long *)(dst + i)           = ((a0 & mask_127) + (b0 & mask_127)) ^ ((a0 ^ b0) & mask_128);
    *(long *)(dst + i + step)    = ((a1 & mask_127) + (b1 & mask_127)) ^ ((a1 ^ b1) & mask_128);
    *(long *)(dst + i + 2*step)  = ((a2 & mask_127) + (b2 & mask_127)) ^ ((a2 ^ b2) & mask_128);
    *(long *)(dst + i + 3*step)  = ((a3 & mask_127) + (b3 & mask_127)) ^ ((a3 ^ b3) & mask_128);
}
}
