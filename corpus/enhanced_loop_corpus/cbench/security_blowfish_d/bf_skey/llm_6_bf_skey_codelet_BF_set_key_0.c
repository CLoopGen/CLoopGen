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
    unsigned long temp;
    for (i = 0; i < (16 + 2); i++) {
        temp = 0;
        ri = *(d++);
        if (d >= end)
            d = data;
        temp |= ri;
        temp <<= 8;

        ri = *(d++);
        if (d >= end)
            d = data;
        temp |= ri;
        temp <<= 8;

        ri = *(d++);
        if (d >= end)
            d = data;
        temp |= ri;
        temp <<= 8;

        ri = *(d++);
        if (d >= end)
            d = data;
        temp |= ri;

        p[i] ^= temp;
    }
}
