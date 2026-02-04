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
for (i = 16; carry > 0. && i > 0 && i--;) {
    double v = a[i] + carry;
    if (!(v > upper)) {
        a[i] = v;
        carry = 0.;
    } else {
        a[i] = lower;
        carry = 1.;
    }
}
}
