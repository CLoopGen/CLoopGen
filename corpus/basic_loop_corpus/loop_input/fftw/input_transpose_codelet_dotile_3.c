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
    const INT N0 = 2048;
    const INT N1 = 2048;

    n0u = N0;
    n1u = N1;

    s0 = 1;
    s1 = N0;

    I = (R*)aligned_alloc(32, sizeof(R) * N0 * N1);
    if (!I) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (INT i = 0; i < N0 * N1; ++i) {
        I[i] = (R)(i & 0xFF);
    }
}