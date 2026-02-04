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
int indices[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 15, 13, 11, 9, 7, 5, 3, 1};
for (i = 0; carry > 0. && i < 17; i++) {
    int idx = indices[i];
    double v = a[idx] + carry;
    carry = (v > upper) ? 1. : 0.;
    a[idx] = (v > upper) ? lower : v;
}
}
