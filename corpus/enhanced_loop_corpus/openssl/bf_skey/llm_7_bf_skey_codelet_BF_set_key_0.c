#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *data;
extern int i;
extern unsigned int *p;
extern unsigned int ri;
extern  unsigned char *d;
extern  unsigned char *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int local_accum[2] = {0}; // Introduce WAW and WAR via staged accumulation
    for (i = 0; i < (16 + 2); i++) {
        local_accum[0] = *(d++);
        if (d >= end) d = data;
        local_accum[0] |= ((unsigned int)(*(d++))) << 8;
        if (d >= end) d = data;
        local_accum[1] = ((unsigned int)(*(d++))) << 16;
        if (d >= end) d = data;
        local_accum[1] |= ((unsigned int)(*(d++))) << 24;
        if (d >= end) d = data;
        ri = local_accum[0] | local_accum[1]; // Combine with artificial dependency between accumulators
        p[i] ^= ri;
        local_accum[0] = ri; // Create artificial reuse (WAW & WAR across iterations)
    }
}
