#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *x;
extern unsigned short *y;
extern unsigned int a;
extern int i;
extern unsigned int carry;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp_carry = carry;
    for (i = 2; i < (6 + 3); i++) {
        unsigned int local_a = (unsigned int)(*x) + (unsigned int)(*y) + temp_carry;
        temp_carry = (local_a >> 16) & 1;
        *y = (unsigned short)local_a;
        --x;
        --y;
    }
    carry = temp_carry;
}
