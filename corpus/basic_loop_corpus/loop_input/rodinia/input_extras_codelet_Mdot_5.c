#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

double *x;
double *y;
int i;
int len4;
double sum0;
double sum1;
double sum2;
double sum3;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024; // 64 MB total for x and y (each double is 8 bytes)
    const size_t num_doubles = total_size / (2 * sizeof(double)); // Two arrays: x and y
    len4 = num_doubles / 4; // Ensure multiple of 4 so loop accesses are safe

    x = aligned_alloc(32, num_doubles * sizeof(double));
    y = aligned_alloc(32, num_doubles * sizeof(double));

    if (!x || !y) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_doubles; idx++) {
        x[idx] = (double)(rand() % 1000) / 10.0;
        y[idx] = (double)(rand() % 1000) / 10.0;
    }

    sum0 = 0.0;
    sum1 = 0.0;
    sum2 = 0.0;
    sum3 = 0.0;
}