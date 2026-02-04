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
if (n > 0) {
    const int total = n * n;
    for (int idx = 0; idx < total; idx++) {
        i = idx / n;
        j = idx % n;
        if (j < i) {
            const int in = i * n;
            y[i] -= matrix[in + j] * y[j];
        } else if (j == i) {
            y[i] = vector[i];
            const int in = i * n;
            for (int k = 0; k < i; k++) {
                y[i] -= matrix[in + k] * y[k];
            }
        }
    }
}
}
