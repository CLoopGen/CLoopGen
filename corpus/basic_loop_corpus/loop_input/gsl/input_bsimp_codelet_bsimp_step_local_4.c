#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

size_t dim;
double y_out[65536];
double *delta;
double *rhs_temp;
double h;
size_t i;

static double *allocate_aligned_double_array(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 32, n * sizeof(double)) != 0) {
        return NULL;
    }
    return (double *)ptr;
}

void init_vars() {
    struct timeval tv_start, tv_end;
    gettimeofday(&tv_start, NULL);

    dim = 65536;
    h = 1.5;

    delta = allocate_aligned_double_array(dim);
    rhs_temp = allocate_aligned_double_array(dim);

    if (!delta || !rhs_temp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < dim; idx++) {
        y_out[idx] = 1.0 + (idx * 0.001);
        delta[idx] = 0.5;
        rhs_temp[idx] = 0.0;
    }

    do {
        gettimeofday(&tv_end, NULL);
        double elapsed = (tv_end.tv_sec - tv_start.tv_sec) + (tv_end.tv_usec - tv_start.tv_usec) / 1e6;
        if (elapsed >= 0.01) break;

        for (size_t iter = 0; iter < dim; iter++) {
            rhs_temp[iter] = h * y_out[iter] - delta[iter];
        }
    } while (1);
}