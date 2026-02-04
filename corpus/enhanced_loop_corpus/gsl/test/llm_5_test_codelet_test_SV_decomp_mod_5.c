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
for (i = 9; i > 0 && carry > 0.; i--) {
    double v = a[i-1] + carry;
    carry = -(v > upper); // Exploits implicit conversion: true -> -1.0, false -> 0.0, but adjusted via ternary logic
    carry += (carry < 0.) ? 2. : 0.; // Normalize carry to 1. if it was set, otherwise remains 0.
    a[i-1] = (v > upper) ? lower : v;
}
}
