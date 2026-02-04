#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;
typedef R E;

R *I = NULL;
INT i;
INT n;
INT is;

void init_vars() {
    n = 16777216; // 16M elements, approximately 128 MB for double
    is = 1;
    I = (R *)aligned_alloc(32, n * sizeof(R));
    if (!I) {
        exit(1);
    }
    for (INT idx = 0; idx < n; ++idx) {
        I[idx] = ((E)1.0); // Initialize to non-zero to allow verification
    }
}