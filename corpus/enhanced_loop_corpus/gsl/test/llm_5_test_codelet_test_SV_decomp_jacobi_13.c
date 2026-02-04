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
for (i = 25; i > 0 && carry > 0.; i--) {
    double v = a[i-1] + carry;
    carry = 0.;
    if (v > upper) {
        a[i-1] = lower;
        carry = 1.;
    } else {
        a[i-1] = v;
    }
}
}
