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
    for (int outer = 0; outer < 2; outer++) {
        for (i = 0; i < (16 + 2) / 2; i++) {
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
        }
        // Adjust i to reflect original indexing after inner loop
        for (int j = 0; j < (16 + 2) / 2; j++) {
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
            p[(16 + 2) / 2 + j] ^= ri;
        }
    }
}
