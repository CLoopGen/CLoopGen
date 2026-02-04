#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef R E;

INT n = 1 << 24; // Approximately 128MB of data for xr, ensuring loop runs ~0.01s
R *xr;
INT xs = 1;
E *o;
INT i;
E sr = 0.0;

void init_vars() {
    xr = (R*)aligned_alloc(32, n * sizeof(R));
    o = (E*)aligned_alloc(32, 2 * ((n / 2)) * sizeof(E)); // Max required: 2 per iteration

    if (!xr || !o) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (INT idx = 0; idx < n; ++idx) {
        xr[idx] = (R)(idx % 1000) + 1.0;
    }
    for (INT idx = 0; idx < 2 * ((n / 2)); ++idx) {
        o[idx] = 0.0;
    }
}