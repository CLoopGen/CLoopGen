#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *cheb12;
size_t i;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // ~256MB for sufficient runtime (~0.01 sec)
    double *data = (double*)calloc(data_size, sizeof(double));
    if (!data) exit(1);

    cheb12 = data;
}

__attribute__((destructor))
static void cleanup() {
    free((void*)cheb12);
}