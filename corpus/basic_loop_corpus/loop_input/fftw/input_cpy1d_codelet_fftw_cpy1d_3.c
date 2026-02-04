#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;

R *I;
R *O;
INT n0;
INT is0;
INT os0;
INT vl;
INT i0;
INT v;

void init_vars() {
    vl = 8;
    n0 = 2000000 / vl;
    is0 = vl;
    os0 = vl;

    size_t total_size = (size_t)n0 * (size_t)vl * sizeof(R);

    I = (R*)aligned_alloc(32, total_size);
    O = (R*)aligned_alloc(32, total_size);

    if (!I || !O) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < (size_t)n0 * (size_t)vl; ++i) {
        I[i] = (R)(i % 1000) / 100.0;
        O[i] = 0.0;
    }
}