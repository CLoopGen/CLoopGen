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
    unsigned long local_ri[2]; // Introduce local state to create WAW and WAR hazards artificially
    int idx;
    for (i = 0; i < (16 + 2); i++) {
        idx = i % 2;
        local_ri[idx] = *(d++);
        if (d >= end) d = data;
        local_ri[idx] <<= 8;
        local_ri[idx] |= *(d++);
        if (d >= end) d = data;
        local_ri[idx] <<= 8;
        local_ri[idx] |= *(d++);
        if (d >= end) d = data;
        local_ri[idx] <<= 8;
        local_ri[idx] |= *(d++);
        if (d >= end) d = data;

        // Create artificial loop-carried dependency via write-after-write on shared index
        // and use previous iteration's value conditionally (introducing RAW)
        if (i > 0 && (i % 2 == 0)) {
            p[i] ^= local_ri[(idx + 1) % 2]; // Use older entry, creating delayed dependency
        }
        p[i] ^= local_ri[idx];
    }
}
