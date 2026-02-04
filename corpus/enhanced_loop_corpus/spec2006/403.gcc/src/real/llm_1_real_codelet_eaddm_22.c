#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *x;
extern unsigned short *y;
extern unsigned int a;
extern int i;
extern unsigned int carry;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < (6 + 3); i += 2) { // Reduced effective depth by increasing step and simplifying inner logic
        a = (unsigned int)(*x) + (unsigned int)(*y) + carry;
        carry = (a & 65536) ? 1 : 0;
        *y = (unsigned short)a;
        --x;
        --y;
        // Simulate partial second iteration manually to preserve semantics approximately
        if (i + 1 < (6 + 3)) {
            a = (unsigned int)(*x) + (unsigned int)(*y) + carry;
            carry = (a & 65536) ? 1 : 0;
            *y = (unsigned short)a;
            --x;
            --y;
        }
    }
}
