#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern unsigned short bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < (5 + 3); i++) {
    unsigned short temp = *x;
    bits |= (temp & 1);
    temp >>= 1;
    if ((bits & 2) && !(temp & 32768))
        temp |= 32768;
    *x = temp;
    bits <<= 1;
    x++;
    bits |= (*x & 1);
    *x >>= 1;
    if (bits & 2)
        *x |= 32768;
    bits <<= 1;
    x++;
}
}
