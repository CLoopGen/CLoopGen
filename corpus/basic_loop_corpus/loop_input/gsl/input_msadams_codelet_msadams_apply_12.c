#include <stdlib.h>
#include <stddef.h>

size_t dim;
double y[1 << 24]; // 16M elements, ~128 MB for double
double *z;
size_t i;

void init_vars() {
    dim = 1 << 20; // 1M elements, ensures ~0.01 sec runtime
    z = &y[0]; // Point z to beginning of y, so z[0*dim + i] = y[i]
}