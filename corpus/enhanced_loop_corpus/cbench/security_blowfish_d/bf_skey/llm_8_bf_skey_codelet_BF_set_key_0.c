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
    for (i = 0; i < (8 + 4); i++) {
        ri = *(d++);
        if (d >= end)
            d = data;
        ri <<= 8;
        ri |= *(d++);
        if (d >= end)
            d = data;
        p[i % 12] ^= ri;
    }
}
