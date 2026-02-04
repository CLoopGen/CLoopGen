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
for (i = 9; carry > 0. && i > 0; --i) {
    for (int unroll = 0; unroll < 1; ++unroll) {
        double v = a[i] + carry;
        carry = (v > upper) ? 1. : 0.;
        a[i] = (v > upper) ? lower : v;
    }
}
}
