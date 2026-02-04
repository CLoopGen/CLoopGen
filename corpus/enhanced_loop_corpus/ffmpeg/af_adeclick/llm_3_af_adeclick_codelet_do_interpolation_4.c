#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern double *vector;
extern int n;
extern int i;
extern int j;
extern double *y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double *y_local = (double*)malloc(n * sizeof(double));
if (!y_local) return;
for (i = 0; i < n; i++) {
    y_local[i] = y[i];
}
for (i = 0; i < n; i++) {
    const int in = i * n;
    double value = vector[i];
    for (j = i - 1; j >= 0; j--) {
        value -= matrix[in + j] * y_local[j];
    }
    y[i] = value;
}
free(y_local);
}
