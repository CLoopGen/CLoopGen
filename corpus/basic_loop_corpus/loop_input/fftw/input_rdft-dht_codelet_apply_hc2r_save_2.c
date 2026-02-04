#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;
typedef R E;

R *I;
R *O;
INT is;
INT os;
INT i;
INT n;

void init_vars() {
    n = 1 << 24; // ~16.7 million elements, roughly 128MB for two arrays of double
    is = 1;
    os = 1;

    I = (R*)aligned_alloc(32, n * sizeof(R));
    O = (R*)aligned_alloc(32, n * sizeof(R));

    if (!I || !O) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (INT idx = 0; idx < n; ++idx) {
        I[idx] = (R)(idx % 1000) / 1000.0;
    }

    for (INT idx = 0; idx < n; ++idx) {
        O[idx] = 0.0;
    }

    i = 0;
}