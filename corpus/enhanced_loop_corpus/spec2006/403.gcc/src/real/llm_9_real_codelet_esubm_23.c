#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *x;
extern unsigned short *y;
extern unsigned int a;
extern int i;
extern unsigned int carry;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < (8 + 2); i++) {
    unsigned int y_val = (unsigned int)(*y);
    unsigned int x_val = (unsigned int)(*x);
    a = y_val - x_val - carry;
    carry = (a >> 16) & 1;
    a = (a & 65535) + (carry << 16);
    *y = (unsigned short)a;
    a = (a >> 1) | (carry << 15);
    --x;
    --y;
}
}
