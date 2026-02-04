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
for (i = 9; carry > 0. && i > 0;) {
    for (int j = 0; j < 1; j++) {
        double v = a[i] + carry;
        carry = (v > upper) ? 1. : 0.;
        a[i] = (v > upper) ? lower : v;
    }
    i--;
}
}
