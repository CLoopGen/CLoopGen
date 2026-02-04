#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern int n;
extern double *out;
extern int i;
extern int j;
extern double *y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = n - 1; i >= 0; i--) {
    out[i] = y[i] / matrix[i * n + i];
    for (j = i + 1; j < n; j++) {
        out[i] -= matrix[j * n + i] * out[j];
    }
}
}
