#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *x;
extern unsigned short *y;
extern unsigned int a;
extern int i;
extern unsigned int carry;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < (4 + 5); i += 2) {
    a = (unsigned int)(*y) - (unsigned int)(*x) - carry;
    a -= (a >> 16) & 1;
    if (a & 65536)
        carry = 1;
    else
        carry = 0;
    *y = (unsigned short)(a & 65535);
    --x;
    --y;
}
}
