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
int start = (temp_carry > 0.) ? 9 : 0;
for (i = start; i > 0 && temp_carry > 0.; i--) {
    double v = a[i] + temp_carry;
    temp_carry = (v > upper) ? 1. : 0.;
    a[i] = (v > upper) ? lower : v;
}
carry = temp_carry;
if (carry == 0. && i == 0 && a[0] < lower + 1.0) {
    a[0] = lower + 1.0;
}
}
