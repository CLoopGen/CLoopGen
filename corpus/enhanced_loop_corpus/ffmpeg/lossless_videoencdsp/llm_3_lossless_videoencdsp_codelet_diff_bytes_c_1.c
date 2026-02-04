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
    // Variant 2: Consecutive Element Processing with Unrolled Access (process two elements per iteration)
    for (i = 0; i <= w - 2 * (int)sizeof(long); i += 2 * sizeof(long)) {
        long a1 = *(long *)(src1 + i);
        long b1 = *(long *)(src2 + i);
        long a2 = *(long *)(src1 + i + sizeof(long));
        long b2 = *(long *)(src2 + i + sizeof(long));

        *(long *)(dst + i) = ((a1 | (~0UL / 255 * 128)) - (b1 & (~0UL / 255 * 127))) ^ ((a1 ^ b1 ^ (~0UL / 255 * 128)) & (~0UL / 255 * 128));
        *(long *)(dst + i + sizeof(long)) = ((a2 | (~0UL / 255 * 128)) - (b2 & (~0UL / 255 * 127))) ^ ((a2 ^ b2 ^ (~0UL / 255 * 128)) & (~0UL / 255 * 128));
    }
    // Handle potential leftover element if width not aligned to 2*long
    if (i <= w - (int)sizeof(long)) {
        long a = *(long *)(src1 + i);
        long b = *(long *)(src2 + i);
        *(long *)(dst + i) = ((a | (~0UL / 255 * 128)) - (b & (~0UL / 255 * 127))) ^ ((a ^ b ^ (~0UL / 255 * 128)) & (~0UL / 255 * 128));
    }
}
