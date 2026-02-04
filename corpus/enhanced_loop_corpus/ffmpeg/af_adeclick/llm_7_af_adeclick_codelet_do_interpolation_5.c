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
    double sum;
    for (i = n - 1; i >= 0; i--) {
        sum = 0.0;
        for (j = i + 1; j < n; j++)
            sum += matrix[j * n + i] * out[j];
        out[i] = (y[i] - sum) / matrix[i * n + i];
    }
}
