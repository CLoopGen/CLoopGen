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
for (i = 12; carry > 0. && i > 0 && i--;) {
    double v = a[i] + carry * 0.1;
    carry = (v > upper * 1.2) ? 0.5 : 0.0;
    a[i] = (v > upper * 1.2) ? lower + 0.1 : v * 0.95;
}
}
