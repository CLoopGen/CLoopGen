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
    for (i = 0; i < (32 + 4); i += 2) {
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
        p[i] ^= ri;
        if (i + 1 < (32 + 4)) {
            unsigned int ri_next = *(d++);
            if (d >= end)
                d = data;
            ri_next <<= 8;
            ri_next |= *(d++);
            if (d >= end)
                d = data;
            ri_next <<= 8;
            ri_next |= *(d++);
            if (d >= end)
                d = data;
            ri_next <<= 8;
            ri_next |= *(d++);
            if (d >= end)
                d = data;
            p[i + 1] ^= ri_next;
        }
    }
}
