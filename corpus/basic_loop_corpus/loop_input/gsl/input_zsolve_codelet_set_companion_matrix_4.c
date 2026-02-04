#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stddef.h>

size_t nc = 8192;
double *m = NULL;
size_t i;
size_t j;

void init_vars() {
    m = (double*)calloc(nc * nc, sizeof(double));
    if (!m) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}