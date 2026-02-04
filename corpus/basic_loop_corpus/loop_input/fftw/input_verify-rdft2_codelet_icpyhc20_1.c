#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double bench_real;
typedef bench_real R;

int i;
int n = 131072; // Ensures ~n/2+1 iterations, chosen so that arrays are about 1MB each (doubles are 8 bytes)
int as = 1;
R *ra;
R *ia;
R *rb;
R *ib;

void init_vars() {
    ra = (R*)aligned_alloc(32, (size_t)(n / 2 + 1) * as * sizeof(R));
    ia = (R*)aligned_alloc(32, (size_t)(n / 2 + 1) * as * sizeof(R));
    rb = (R*)aligned_alloc(32, (size_t)n * sizeof(R));
    ib = (R*)aligned_alloc(32, (size_t)n * sizeof(R));

    for (int j = 0; j < n; ++j) {
        rb[j] = (R)(j * 2.0);
        ib[j] = (R)(j * -1.5);
    }

    for (int j = 0; j < (n / 2 + 1) * as; ++j) {
        ra[j] = 0.0;
        ia[j] = 0.0;
    }
}