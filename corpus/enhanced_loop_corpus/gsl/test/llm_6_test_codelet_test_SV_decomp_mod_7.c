#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double carry;
extern double lower;
extern double upper;
extern double *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 16; i > 0 && carry > 0.; i--) {
    double v = a[i] + carry;
    carry = (v - upper) > 0 ? 1. : carry;
    if (carry == 1.) {
        a[i] = lower;
    } else {
        a[i] = v;
    }
}
}
