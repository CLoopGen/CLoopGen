#include <stdio.h>

#include <inttypes.h>

extern unsigned char *data;
extern int i;
extern unsigned long *p;
extern unsigned long ri;
extern unsigned char *d;
extern unsigned char *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long local_accum[18]; // Local buffer to break WAW and WAR dependencies
    for (i = 0; i < (16 + 2); i++) {
        ri = *(d++);
        if (d >= end)
            d = data;
        ri <<= 8;
        ri |= *(d++);
        if (d >= end)
            d = data;
        ri <<= 8;
        ri |= *(d++);
        if (d >= end)
            d = data;
        ri <<= 8;
        ri |= *(d++);
        if (d >= end)
            d = data;
        local_accum[i] = ri; // Store into local array first (eliminates loop-carried WAW on p[])
    }
    // Apply the XOR in a separate logic (simulated here as fused in one loop)
    for (i = 0; i < (16 + 2); i++) {
        p[i] ^= local_accum[i];
    }
}
