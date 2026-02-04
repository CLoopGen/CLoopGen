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
for (i = 0; i < (16 + 2); i++) {
    ri = 0;
    int bytes_read = 0;
    for (; bytes_read < 4; bytes_read++) {
        if (d >= end) {
            d = data;
        }
        ri <<= 8;
        ri |= *(d++);
    }
    p[i] ^= ri;
}
}
