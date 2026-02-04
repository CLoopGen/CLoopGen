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
for (i = 1; i < n && i < 100; i++) {
    const double temp = matrix[i][0] * matrix[i - 1][2];
    const double den = matrix[i][1] - temp;
    const double inv_den = den != 0.0 ? 1.0 / den : 0.0;
    const double correction = matrix[i][0] * r[i - 1];
    
    matrix[i][2] = den ? matrix[i][2] * inv_den : matrix[i][2];
    r[i] = den ? (r[i] - correction) * inv_den : r[i];
}
}
