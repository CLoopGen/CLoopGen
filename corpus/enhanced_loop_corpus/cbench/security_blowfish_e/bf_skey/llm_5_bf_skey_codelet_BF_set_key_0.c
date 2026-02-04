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
    if (!(d < end)) d = data;
    ri = *(d++);
    ri <<= 8;
    if (d < end) {
        ri |= *(d++);
    } else {
        d = data;
        ri |= *(d++);
    }
    ri <<= 8;
    if (d < end) {
        ri |= *(d++);
    } else {
        d = data;
        ri |= *(d++);
    }
    ri <<= 8;
    if (d < end) {
        ri |= *(d++);
    } else {
        d = data;
        ri |= *(d++);
    }
    p[i] ^= ri;
}
}
