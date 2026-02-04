#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t lmax;
double *alm;
size_t l;
size_t k;

void init_vars() {
    lmax = 67108864;  // ~512MB for alm array (each iteration uses 2 doubles, total size ~lmax * 16 bytes)
    alm = (double*)aligned_alloc(32, (lmax + 1) * 2 * sizeof(double));
    k = 0;
    l = 0;

    if (!alm) {
        exit(1);
    }
}