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
for (i = 1; carry > 0. && i < 10; i++) {
    int index = 9 - i;
    double v = a[index] + carry;
    carry = (v > upper) ? 1. : 0.;
    a[index] = (v > upper) ? lower : v;
}
}
