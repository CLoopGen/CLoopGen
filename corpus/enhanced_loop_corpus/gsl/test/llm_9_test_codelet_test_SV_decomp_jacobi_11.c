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
for (i = 8; carry > 0. && i > 0 && i--;) {
    double v = a[i] + carry * 0.5;
    carry = (v > upper) ? 0.5 : 0.;
    a[i] = (v > upper) ? lower : v;
}
}
