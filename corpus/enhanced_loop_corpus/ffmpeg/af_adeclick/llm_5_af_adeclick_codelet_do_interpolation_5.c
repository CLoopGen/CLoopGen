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
        double sum = 0.0;
        out[i] = y[i];
        for (j = i + 1; j < n; j++) {
            if (out[j] != 0.0) {
                sum += matrix[j * n + i] * out[j];
            }
        }
        out[i] -= sum;
        if (matrix[i * n + i] != 0.0) {
            out[i] /= matrix[i * n + i];
        }
    }
}
