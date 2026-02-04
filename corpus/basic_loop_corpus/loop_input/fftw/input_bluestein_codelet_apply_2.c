#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double R;
typedef ptrdiff_t INT;
typedef R E;

R *ri;
R *ii;
INT i;
INT n;
INT is;
R *w;
R *b;

void init_vars() {
    n = 8388608; // Size to achieve ~0.01 sec runtime (adjustable based on system)
    is = 1;

    ri = (R*)aligned_alloc(32, n * sizeof(R));
    ii = (R*)aligned_alloc(32, n * sizeof(R));
    w = (R*)aligned_alloc(32, 2 * n * sizeof(R));
    b = (R*)aligned_alloc(32, 2 * n * sizeof(R));

    for (INT idx = 0; idx < n; ++idx) {
        ri[idx * is] = sin(idx * 0.01);
        ii[idx * is] = cos(idx * 0.01);
    }

    for (INT idx = 0; idx < n; ++idx) {
        w[2 * idx] = cos(idx * 0.02);
        w[2 * idx + 1] = sin(idx * 0.02);
    }

    for (INT idx = 0; idx < 2 * n; ++idx) {
        b[idx] = 0.0;
    }
}