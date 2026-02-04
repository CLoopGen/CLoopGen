#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int order_min = 0;
int order_max = 65535;
double result_array[65536];
unsigned int ii;
double *aa;

void init_vars() {
    const size_t size = order_max - order_min + 1;
    aa = (double*)aligned_alloc(32, size * sizeof(double));
    if (!aa) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < size; i++) {
        aa[i] = (double)(rand() % 1000) / 3.33;
    }
    memset(result_array, 0, size * sizeof(double));
}