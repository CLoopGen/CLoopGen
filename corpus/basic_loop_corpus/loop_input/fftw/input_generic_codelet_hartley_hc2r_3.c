#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef R E;

INT n = 1 << 24; // Approximately 16M elements, leading to ~256MB of data for double

R *x;
INT xs = 1;
E *o;
INT i;
E sr;

void init_vars() {
    x = (R*)aligned_alloc(32, ((size_t)n + 1) * sizeof(R));
    o = (E*)aligned_alloc(32, (size_t)n * sizeof(E) * 2); // Over-allocate to be safe

    if (!x || !o) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (INT j = 0; j <= n; ++j) {
        x[j] = (R)(j % 1000) / 10.0;
    }
    for (INT j = 0; j < n * 2; ++j) {
        o[j] = 0.0;
    }

    sr = 0.0;
}