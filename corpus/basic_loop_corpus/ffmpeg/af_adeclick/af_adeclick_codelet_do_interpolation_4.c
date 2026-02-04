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
for (i = 0; i < n; i++) {
    const int in = i * n;
    double value;
    value = vector[i];
    for (j = 0; j < i; j++)
        value -= matrix[in + j] * y[j];
    y[i] = value;
}

}
