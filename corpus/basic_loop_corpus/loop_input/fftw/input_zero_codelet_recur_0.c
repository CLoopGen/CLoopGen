#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;
typedef R E;

R *ri;
R *ii;
INT i;
INT n;
INT is;

void init_vars() {
    n = 16777216; // 16M elements, ~128MB for two arrays of doubles (8 bytes each)
    is = 1;
    
    ri = (R*)aligned_alloc(32, n * is * sizeof(R));
    ii = (R*)aligned_alloc(32, n * is * sizeof(R));

    if (!ri || !ii) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}

// Ensure symbols are defined
R* ri;
R* ii;
INT i;
INT n;
INT is;