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
for (i = 16; carry > 0. && i > 0 && i--;) {
    double v = a[i] + carry;
    double old_carry = carry;
    carry = (v > upper) ? 1. : 0.;
    a[i] = (old_carry != 0.) ? ((v > upper) ? lower : v) : a[i];
}
}
