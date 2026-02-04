#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double rematrix_volume = 1.5;

int stride = 64;
int i, j;

double *matrix_param;

void init_vars() {
    size_t matrix_size = stride * 64 * sizeof(double);
    matrix_param = aligned_alloc(32, matrix_size);
    if (!matrix_param) {
        exit(1);
    }
    for (int idx = 0; idx < stride * 64; idx++) {
        matrix_param[idx] = (double)(idx + 1);
    }
    rematrix_volume = 1.000002; 
}