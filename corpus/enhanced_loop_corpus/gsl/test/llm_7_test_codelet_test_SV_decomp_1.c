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
double temp_carry = carry;
for (i = 9; temp_carry > 0. && i > 0 && i--;) {
    double v = a[i] + temp_carry;
    temp_carry = (v > upper) ? 1. : 0.;
    a[i] = (v <= upper) ? v : lower;
}
carry = temp_carry;
}
