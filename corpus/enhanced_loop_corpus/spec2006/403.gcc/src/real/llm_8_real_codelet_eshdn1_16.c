#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern unsigned short bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < (8 + 4); i += 2) {
    bits |= (*x & 1);
    *x >>= 1;
    if (bits & 2)
        *x |= 32768;
    bits <<= 1;
    ++x;
}
}
