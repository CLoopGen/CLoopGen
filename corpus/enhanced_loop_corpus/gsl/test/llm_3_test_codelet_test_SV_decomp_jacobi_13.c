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
for (i = 25; carry > 0. && i > 0 && i--;) {
    int index = (i * 3) % 100; // Strided access with modulo to stay within bounds
    double v = a[index] + carry;
    carry = (v > upper) ? 1. : 0.;
    a[index] = (v > upper) ? lower : v;
}
}
