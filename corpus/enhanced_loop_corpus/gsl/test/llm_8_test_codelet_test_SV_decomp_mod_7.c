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
double local_carry = carry;
for (i = 16; local_carry > 0. && i > 0 && i--;) {
    double v = a[i] + local_carry;
    a[i] = (v > upper) ? lower : v;
    local_carry = (v > upper) ? 1. : 0.;
}
carry = local_carry;
}
