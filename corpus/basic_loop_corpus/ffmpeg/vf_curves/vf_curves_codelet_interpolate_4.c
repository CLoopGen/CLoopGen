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
    const double den = matrix[i][1] - matrix[i][0] * matrix[i - 1][2];
    const double k = den ? 1. / den : 1.;
    matrix[i][2] *= k;
    r[i] = (r[i] - matrix[i][0] * r[i - 1]) * k;
}

}
