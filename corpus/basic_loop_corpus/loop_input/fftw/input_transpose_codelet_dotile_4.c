#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;

INT n0l = 0;
INT n0u;
INT n1l = 0;
INT n1u;
R *I;
INT s0;
INT s1;
INT i0;
INT i1;

void init_vars() {
    const INT N0 = 256;
    const INT N1 = 256;

    n0u = N0;
    n1u = N1;

    s0 = 1;
    s1 = N0;

    size_t total_size = (size_t)(s1 * n1u + s0 * n0u + 2);
    I = (R*)aligned_alloc(sizeof(R), total_size * sizeof(R));
    if (!I) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; ++i) {
        I[i] = (R)(i % 1000) + 0.5;
    }
}