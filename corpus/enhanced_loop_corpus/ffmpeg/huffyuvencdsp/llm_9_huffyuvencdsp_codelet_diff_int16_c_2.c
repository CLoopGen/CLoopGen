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
for (i = 0; i <= w - (int)sizeof(long); i += sizeof(long)) {
    long a1 = *(long *)(src1 + i);
    long a2 = *(long *)(src1 + i + sizeof(long)/2);
    long b1 = *(long *)(src2 + i);
    long b2 = *(long *)(src2 + i + sizeof(long)/2);
    *(long *)(dst + i) = ((a1 | pw_msb) - (b1 & pw_lsb)) ^ ((a1 ^ b1 ^ pw_msb) & pw_msb);
    *(long *)(dst + i + sizeof(long)/2) = ((a2 | pw_msb) - (b2 & pw_lsb)) ^ ((a2 ^ b2 ^ pw_msb) & pw_msb);
}
}
