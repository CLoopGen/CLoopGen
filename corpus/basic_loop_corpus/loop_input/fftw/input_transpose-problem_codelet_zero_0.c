#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;
typedef R E;

R *I = NULL;
INT i = 0;
INT N = 0;

void init_vars() {
    N = 134217728 / sizeof(R);  // ~134 million elements for ~1 second, scaled to sizeof(double)
    I = (R*)aligned_alloc(_Alignof(R), (size_t)N * sizeof(R));
    if (!I) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}