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
    for (i = 0; i < (16 + 2); i += 4) {
        for (int unroll = 0; unroll < 4 && (i + unroll) < (16 + 2); unroll++) {
            int idx = i + unroll;
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
            p[idx] ^= ri;
        }
    }
}
