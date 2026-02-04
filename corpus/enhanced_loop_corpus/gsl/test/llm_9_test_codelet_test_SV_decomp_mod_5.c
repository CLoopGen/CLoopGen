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
for (i = 17; carry > 0. && i > 0 && (i -= 2);) {
    double v = a[i-1] + carry;
    carry = (v >= upper) ? 1. : 0.;
    a[i-1] = (v >= upper) ? lower : v;
    if (carry == 0.) break;
    v = a[i-2] + carry;
    carry = (v >= upper) ? 1. : 0.;
    a[i-2] = (v >= upper) ? lower : v;
}
}
