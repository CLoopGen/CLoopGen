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
    for (i = 0; i < (32 + 8); i += 2) {
        unsigned long ri1 = *(d++);
        if (d >= end)
            d = data;
        ri1 <<= 8;
        ri1 |= *(d++);
        if (d >= end)
            d = data;
        ri1 <<= 8;
        ri1 |= *(d++);
        if (d >= end)
            d = data;
        ri1 <<= 8;
        ri1 |= *(d++);
        if (d >= end)
            d = data;

        unsigned long ri2 = *(d++);
        if (d >= end)
            d = data;
        ri2 <<= 8;
        ri2 |= *(d++);
        if (d >= end)
            d = data;
        ri2 <<= 8;
        ri2 |= *(d++);
        if (d >= end)
            d = data;
        ri2 <<= 8;
        ri2 |= *(d++);
        if (d >= end)
            d = data;

        p[i] ^= ri1;
        if (i + 1 < (32 + 8))
            p[i + 1] ^= ri2;
    }
}
