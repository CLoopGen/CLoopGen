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
for (i = 0; i <= w - (int)sizeof(long); i += sizeof(long)) {
    long a = *(long *)(src1 + i);
    long b = *(long *)(src2 + i);
    long c = a ^ b;
    long mask1 = ~0UL / 255 * 128;
    long mask2 = ~0UL / 255 * 127;
    long term1 = (a | mask1) - (b & mask2);
    long term2 = (c ^ mask1) & mask1;
    *(long *)(dst + i) = term1 ^ term2;
}
}
