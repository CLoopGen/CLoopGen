#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern unsigned short bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < (6 + 3); i++) {
    if (!(*x & 1)) {
        *x >>= 1;
        bits <<= 1;
        ++x;
        continue;
    }
    bits |= 1;
    *x >>= 1;
    if (bits & 2)
        *x |= 32768;
    bits <<= 1;
    ++x;
}
}
