#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t N = 1024;
size_t tda = 2048;
size_t i;
size_t j;
double *data;
int status;

void init_vars() {
    const size_t total_size = N * tda;
    data = (double*)calloc(total_size, sizeof(double));
    if (!data) {
        status = -1;
        return;
    }

    for (size_t idx = 0; idx < total_size; idx++) {
        data[idx] = 12345. + idx;
    }

    status = 0;
}