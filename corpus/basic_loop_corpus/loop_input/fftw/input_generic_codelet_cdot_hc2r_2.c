#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef R E;

INT n = 131072; // Size chosen so that loop runs ~0.01s; ensures i+i < n => i < n/2

E *x;
R *w;
INT i;
E rr = 0.0;
E ii = 0.0;

void init_vars() {
    x = aligned_alloc(32, n * sizeof(E));
    w = aligned_alloc(32, n * sizeof(R));

    for (INT j = 0; j < n; ++j) {
        x[j] = 1.0 + j * 0.0001;
        w[j] = 0.5 + j * 0.00005;
    }
}