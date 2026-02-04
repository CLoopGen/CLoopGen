#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double (*matrix)[3];
extern double *r;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < n; i++) {
    const int curr = i;
    const int prev = i - 1;
    const double den = matrix[curr][1] - matrix[curr][0] * matrix[prev][2];
    const double k = den ? 1. / den : 1.;
    matrix[curr][2] = matrix[curr][2] * k;
    r[curr] = (r[curr] - matrix[curr][0] * r[prev]) * k;
}
}
