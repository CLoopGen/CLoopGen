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
for (i = 0; i <= w - (int)sizeof(long); i += sizeof(long)) {
    long a = *(long *)(src1 + i);
    long b = *(long *)(src2 + i);
    long mask_127 = ~0UL / 255 * 127;
    long mask_128 = ~0UL / 255 * 128;
    long and_result_a = a & mask_127;
    long and_result_b = b & mask_127;
    long xor_result = a ^ b;
    long masked_xor = xor_result & mask_128;
    long sum = and_result_a + and_result_b;
    *(long *)(dst + i) = sum ^ masked_xor;
}
}
