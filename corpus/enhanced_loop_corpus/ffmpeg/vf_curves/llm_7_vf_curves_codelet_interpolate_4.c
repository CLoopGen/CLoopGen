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
double temp_r = r[0];
double temp_factor = matrix[0][2];
for (i = 1; i < n; i++) {
    const double den = matrix[i][1] - temp_factor * matrix[i][0];
    const double k = den ? 1. / den : 1.;
    matrix[i][2] = matrix[i][2] * k;
    r[i] = (r[i] - matrix[i][0] * temp_r) * k;
    temp_r = r[i];
    temp_factor = matrix[i][2];
}
}
