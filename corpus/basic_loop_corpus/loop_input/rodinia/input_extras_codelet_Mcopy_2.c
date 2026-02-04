#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

int len;
double *x;
double *y;
int i;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Estimate data size for ~0.01 seconds runtime
    // Start with 64 million doubles (512 MB) and adjust if needed
    len = 64 * 1024 * 1024;

    x = (double*)aligned_alloc(32, len * sizeof(double));
    y = (double*)aligned_alloc(32, len * sizeof(double));

    if (!x || !y) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize x with some values
    for (int j = 0; j < len; j++) {
        x[j] = (double)(j % 1000) / 1.234;
    }

    // Warm-up run to estimate execution time
    for (int iter = 0; iter < 1; iter++) {
        for (int j = 0; j < len; j++) {
            y[j] = x[j];
        }
    }

    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

    // Adjust problem size if execution was too fast or too slow
    if (elapsed < 0.008 || elapsed > 0.015) {
        double factor = 0.01 / (elapsed > 0 ? elapsed : 0.01);
        int new_len = (int)((double)len * factor);
        new_len = (new_len < 1000) ? 1000 : new_len;

        free(x);
        free(y);

        len = new_len;
        x = (double*)aligned_alloc(32, len * sizeof(double));
        y = (double*)aligned_alloc(32, len * sizeof(double));

        if (!x || !y) {
            fprintf(stderr, "Reallocation failed\n");
            exit(1);
        }

        for (int j = 0; j < len; j++) {
            x[j] = (double)(j % 1000) / 1.234;
        }
    }

    // Zero out y to ensure clean state before benchmarking
    memset(y, 0, len * sizeof(double));
}