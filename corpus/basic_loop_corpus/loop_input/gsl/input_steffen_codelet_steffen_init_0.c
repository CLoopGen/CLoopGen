#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

#define DATA_SIZE (1 << 20)

double x_array[DATA_SIZE];
double y_array[DATA_SIZE];
size_t size = DATA_SIZE;
size_t i;

double *a;
double *b;
double *c;
double *d;
double *y_prime;

void init_vars() {
    a = malloc((size - 1) * sizeof(double));
    b = malloc((size - 1) * sizeof(double));
    c = malloc((size - 1) * sizeof(double));
    d = malloc((size - 1) * sizeof(double));
    y_prime = malloc(size * sizeof(double));

    for (size_t idx = 0; idx < size; idx++) {
        x_array[idx] = idx * 0.01;
        y_array[idx] = x_array[idx] * x_array[idx];
        y_prime[idx] = 2 * x_array[idx];
    }
}