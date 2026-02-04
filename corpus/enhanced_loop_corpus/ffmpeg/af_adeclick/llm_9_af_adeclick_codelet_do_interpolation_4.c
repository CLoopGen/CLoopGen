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
for (i = 0; i < n; i += 2) {
    if (i + 1 < n) {
        const int in0 = i * n, in1 = (i + 1) * n;
        double value0 = vector[i], value1 = vector[i + 1];
        for (j = 0; j < i; j++) {
            value0 -= matrix[in0 + j] * y[j];
            value1 -= matrix[in1 + j] * y[j];
        }
        y[i] = value0;
        y[i + 1] = value1;
    } else {
        const int in = i * n;
        double value = vector[i];
        for (j = 0; j < i; j++) {
            value -= matrix[in + j] * y[j];
        }
        y[i] = value;
    }
}
}
