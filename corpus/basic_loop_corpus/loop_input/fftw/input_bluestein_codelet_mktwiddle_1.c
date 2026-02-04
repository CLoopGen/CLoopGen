#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef R E;

INT i;
INT n = 1 << 23; // Approximately 8M elements, leading to ~16M iterations and sufficient data size
INT nb;
R *w;
R *W;
E nbf = 16.0;

void init_vars() {
    nb = n;
    nbf = 16.0;

    w = (R*)aligned_alloc(32, 2 * n * sizeof(R));
    W = (R*)aligned_alloc(32, 2 * n * sizeof(R));

    if (!w || !W) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (INT j = 0; j < 2 * n; ++j) {
        w[j] = (R)(j + 1);
        W[j] = 0.0;
    }
}