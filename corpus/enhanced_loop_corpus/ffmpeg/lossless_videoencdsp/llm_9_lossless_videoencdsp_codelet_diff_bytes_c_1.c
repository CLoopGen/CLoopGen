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
intptr_t step = sizeof(long) * 2;
for (i = 0; i <= w - (int)sizeof(long) * 2; i += step) {
    long a1 = *(long *)(src1 + i);
    long b1 = *(long *)(src2 + i);
    long a2 = *(long *)(src1 + i + sizeof(long));
    long b2 = *(long *)(src2 + i + sizeof(long));
    *(long *)(dst + i) = ((a1 | (~0UL / 255 * 128)) - (b1 & (~0UL / 255 * 127))) ^ ((a1 ^ b1 ^ (~0UL / 255 * 128)) & (~0UL / 255 * 128));
    *(long *)(dst + i + sizeof(long)) = ((a2 | (~0UL / 255 * 128)) - (b2 & (~0UL / 255 * 127))) ^ ((a2 ^ b2 ^ (~0UL / 255 * 128)) & (~0UL / 255 * 128));
}
}
