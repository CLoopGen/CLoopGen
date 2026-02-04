#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int order_min = 0;
int order_max = 65535;
double *bb = NULL;
double result_array[65536];
unsigned int ii;

void init_vars() {
    const size_t data_size = 65536 * sizeof(double);
    bb = (double*)aligned_alloc(32, data_size);
    if (!bb) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < 65536; i++) {
        bb[i] = (double)(i * 2.5);
    }

    memset(result_array, 0, sizeof(result_array));

    order_min = 0;
    order_max = 65535;
}