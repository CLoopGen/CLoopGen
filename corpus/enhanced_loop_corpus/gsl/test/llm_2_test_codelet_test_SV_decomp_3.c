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
    double v = a[i-4] + carry;
    carry = (v > upper) ? 1. : 0.;
    a[i-4] = (v > upper) ? lower : v;
}
}
