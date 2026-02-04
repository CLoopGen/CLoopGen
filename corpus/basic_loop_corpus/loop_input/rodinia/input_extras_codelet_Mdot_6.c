#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len;
double *x;
double *y;
int i;
double sum;

void init_vars() {
    len = 20000000; // Approximate size to run loop for ~0.01 seconds

    x = (double*)malloc(len * sizeof(double));
    y = (double*)malloc(len * sizeof(double));

    for (int j = 0; j < len; j++) {
        x[j] = (double)(j % 100) / 10.0;
        y[j] = (double)((j + 5) % 95) / 9.0;
    }

    i = 0;
    sum = 0.0;
}