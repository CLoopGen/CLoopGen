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
double (*mat)[3] = matrix;
double *rr = r;
for (i = 1; i < n; i++) {
    const double den = mat[i][1] - mat[i][0] * mat[i-1][2];
    const double k = den ? 1. / den : 1.;
    mat[i][2] *= k;
    rr[i] = (rr[i] - mat[i][0] * rr[i-1]) * k;
}
}
