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
for (i = 50; carry > 0. && i > 0 && i--;) {
    double v1 = a[i-1] + carry;
    double v2 = a[i-2] + carry * 0.5;
    carry = (v1 > upper) ? ((v2 > upper) ? 2. : 1.) : ((v2 > upper) ? 1. : 0.);
    a[i-1] = (v1 > upper) ? lower : v1;
    if (i > 1) a[i-2] = (v2 > upper) ? lower : v2;
}
}
