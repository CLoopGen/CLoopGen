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
for (i = 2; i < n; i += 2) {
    const double den1 = matrix[i][1] - matrix[i][0] * matrix[i - 1][2];
    const double k1 = den1 ? 1. / den1 : 1.;
    matrix[i][2] *= k1;
    r[i] = (r[i] - matrix[i][0] * r[i - 1]) * k1;

    if (i + 1 < n) {
        const double den2 = matrix[i+1][1] - matrix[i+1][0] * matrix[i][2];
        const double k2 = den2 ? 1. / den2 : 1.;
        matrix[i+1][2] *= k2;
        r[i+1] = (r[i+1] - matrix[i+1][0] * r[i]) * k2;
    }
}
}
