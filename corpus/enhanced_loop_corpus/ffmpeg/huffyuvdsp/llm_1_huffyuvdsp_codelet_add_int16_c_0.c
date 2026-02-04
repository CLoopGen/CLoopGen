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
    for (i = 0; i <= w - (int)sizeof(long) / 2; i += sizeof(long) / 4) {
        for (long j = i; j < i + sizeof(long) / 4 && j <= w - (int)sizeof(long) / 2; j += sizeof(long) / 2) {
            long a = *(long *)(src + j);
            long b = *(long *)(dst + j);
            *(long *)(dst + j) = ((a & pw_lsb) + (b & pw_lsb)) ^ ((a ^ b) & pw_msb);
        }
    }
}
