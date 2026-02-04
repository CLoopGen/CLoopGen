#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src1;
extern  uint16_t *src2;
extern int w;
extern long i;
extern unsigned long pw_lsb;
extern unsigned long pw_msb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every other long-sized element)
    for (i = 0; i <= w - (int)sizeof(long) / 2; i += sizeof(long)) {
        long a = *(long *)(src1 + i);
        long b = *(long *)(src2 + i);
        *(long *)(dst + i) = ((a | pw_msb) - (b & pw_lsb)) ^ ((a ^ b ^ pw_msb) & pw_msb);
    }
}
