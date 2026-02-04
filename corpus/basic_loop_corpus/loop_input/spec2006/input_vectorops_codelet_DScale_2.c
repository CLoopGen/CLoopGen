#include <stdlib.h>
#include <stdint.h>

double *vec;
int n;
double scale;
int x;

void init_vars() {
    n = 16777216; // 16M elements, ~128MB for double array
    vec = (double*)aligned_alloc(32, n * sizeof(double));
    scale = 1.5;
    x = 0;

    for (int i = 0; i < n; i++) {
        vec[i] = (double)(i & 1023) + 1.0;
    }
}