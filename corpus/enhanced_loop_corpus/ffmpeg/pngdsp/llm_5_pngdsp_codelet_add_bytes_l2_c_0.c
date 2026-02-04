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
        long sum_part = (a & mask_127) + (b & mask_127);
        long xor_part = (a ^ b) & mask_128;
        long result = sum_part ^ xor_part;
        if (sum_part >= mask_127) {
            *(long *)(dst + i) = result;
        } else {
            *(long *)(dst + i) = a ^ b;
        }
    }
}
