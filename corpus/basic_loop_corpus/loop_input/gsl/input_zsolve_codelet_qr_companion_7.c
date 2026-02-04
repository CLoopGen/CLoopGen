#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *h;
size_t nc;
size_t i;
size_t m;
size_t n;

void init_vars() {
    nc = 1024;
    m = 1;
    n = 1024;
    size_t rows = n + 1;
    size_t total_elements = rows * nc;
    h = (double*)calloc(total_elements, sizeof(double));
}

void loop();