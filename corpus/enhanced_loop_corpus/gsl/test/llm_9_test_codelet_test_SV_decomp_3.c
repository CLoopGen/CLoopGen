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
for (i = 32; carry > 0. && i > 0 && i--;) {
    double v = a[i-1] + carry * 0.5;
    carry = (v > upper) ? 1.5 : 0.5;
    a[i-1] = (v > upper) ? lower + 0.1 : v - 0.1;
}
}
