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
    double temp;
    for (i = n - 1; i >= 0; i--) {
        temp = y[i];
        for (j = i + 1; j < n; j++)
            temp -= matrix[j * n + i] * out[j];
        out[i] = temp / matrix[i * n + i];
    }
}
