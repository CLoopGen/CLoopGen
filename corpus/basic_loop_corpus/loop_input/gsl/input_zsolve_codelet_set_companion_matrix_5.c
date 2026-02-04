#include <stdlib.h>
#include <stdint.h>

size_t nc = 10000;
double *m;
size_t i;

void init_vars() {
    m = (double*)calloc(nc * nc, sizeof(double));
}