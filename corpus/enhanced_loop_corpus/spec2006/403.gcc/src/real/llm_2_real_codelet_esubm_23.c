#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *x;
extern unsigned short *y;
extern unsigned int a;
extern int i;
extern unsigned int carry;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access (access every second element)
    for (i = 2; i < (6 + 3); i++) {
        a = (unsigned int)(*(y - 2*i)) - (unsigned int)(*(x - 2*i)) - carry;
        if (a & 65536)
            carry = 1;
        else
            carry = 0;
        *(y - 2*i) = (unsigned short)a;
    }
}
