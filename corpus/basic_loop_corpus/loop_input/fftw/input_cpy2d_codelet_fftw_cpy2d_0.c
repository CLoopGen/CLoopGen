#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;

R *I;
R *O;
INT n0 = 1024;
INT is0 = 1;
INT os0 = 1;
INT n1 = 1024;
INT is1 = 1024;
INT os1 = 1024;
INT i0;
INT i1;

void init_vars() {
    size_t total_size = (size_t)n0 * n1 * sizeof(R);
    I = (R*)aligned_alloc(32, total_size);
    O = (R*)aligned_alloc(32, total_size);

    if (!I || !O) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < (size_t)n0 * n1; ++i) {
        I[i] = (R)(i % 1000) / 10.0;
        O[i] = 0.0;
    }
}