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
for (i = 0; i <= w - (int)sizeof(long) / 2; i += sizeof(long) / 2) {
    long a = *(long *)(src1 + i);
    long b = *(long *)(src2 + i);
    long c = ((a | pw_msb) - (b & pw_lsb));
    long d = ((a ^ b ^ pw_msb) & pw_msb);
    *(long *)(dst + i) = (c ^ d) + (a & b);
}
}
