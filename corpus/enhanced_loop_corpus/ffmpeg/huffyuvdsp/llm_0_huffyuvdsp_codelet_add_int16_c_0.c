#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern int w;
extern long i;
extern unsigned long pw_lsb;
extern unsigned long pw_msb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= w - (int)sizeof(long) / 2; i += sizeof(long) / 2) {
        long a = *(long *)(src + i);
        long b = *(long *)(dst + i);
        *(long *)(dst + i) = ((a & pw_lsb) + (b & pw_lsb)) ^ ((a ^ b) & pw_msb);
    }
}
