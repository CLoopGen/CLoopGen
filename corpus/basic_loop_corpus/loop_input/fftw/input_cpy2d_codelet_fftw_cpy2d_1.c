#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;

R *I = NULL;
R *O = NULL;
INT n0 = 0;
INT is0 = 0;
INT os0 = 0;
INT n1 = 0;
INT is1 = 0;
INT os1 = 0;
INT i0 = 0;
INT i1 = 0;

void init_vars() {
    n0 = 1024;
    n1 = 1024;
    is0 = 1;
    is1 = n0;
    os0 = 1;
    os1 = n0;

    size_t total_size = (size_t)n0 * n1 * sizeof(R);

    I = aligned_alloc(64, total_size);
    O = aligned_alloc(64, total_size);

    if (!I || !O) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (INT idx = 0; idx < n0 * n1; ++idx) {
        I[idx] = (R)(idx & 511);
    }

    for (INT idx = 0; idx < n0 * n1; ++idx) {
        O[idx] = 0.0;
    }
}