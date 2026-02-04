#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double x_array[131072];
double y_array[131072];
size_t size = 131071;
double *m;
size_t i;

void init_vars() {
    m = malloc((size) * sizeof(double));
    for (size_t idx = 0; idx < size + 1; idx++) {
        x_array[idx] = idx * 0.01;
        y_array[idx] = x_array[idx] * x_array[idx];
    }
}