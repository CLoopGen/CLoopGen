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
double prev_carry = carry;
for (i = 25; prev_carry > 0. && i > 0 && i--;) {
    double v = a[i] + prev_carry;
    double new_carry = (v > upper) ? 1. : 0.;
    a[i] = (v <= upper) ? v : lower;
    prev_carry = new_carry;
}
carry = prev_carry;
}
