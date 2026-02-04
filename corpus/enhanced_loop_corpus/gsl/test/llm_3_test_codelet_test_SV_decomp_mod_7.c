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
for (i = 0; carry > 0. && i < 17; i++) {
    int idx = 16 - i;
    double v = a[idx] + carry;
    carry = (v > upper) ? 1. : 0.;
    a[idx] = (v > upper) ? lower : v;
}
}
