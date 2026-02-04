#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int i_min = 0;
int i_max;
int n;

double *b_ve;

void init_vars() {
    n = 16777216;  // 16M elements, ~128 MB for doubles

    b_ve = (double*)aligned_alloc(32, n * sizeof(double));
    if (!b_ve) {
        exit(1);
    }

    for (int idx = 0; idx < n; idx++) {
        b_ve[idx] = (idx == n - 2) ? 0.0 : 1.0;
    }

    i_min = 0;
    i_max = n; 
}