#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *cheb24;
size_t i;

void init_vars() {
    // Allocate 24-element array for cheb24
    double *data = (double *)calloc(24, sizeof(double));
    if (!data) {
        exit(1);
    }

    // Initialize data with non-zero values to make scaling observable
    for (size_t idx = 0; idx < 24; idx++) {
        data[idx] = (double)(idx + 1) * 100.0;
    }

    // Assign the allocated array to cheb24 pointer
    cheb24 = data;
}

// Ensure that when loop() is called, it operates on valid memory
// The loop runs from i = 1 to i < 24, so we need exactly 24 elements