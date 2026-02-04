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
    N = 16777216; // 16M elements * sizeof(double) = 128MB
    I = (R*)aligned_alloc(32, N * sizeof(R));
    if (!I) {
        exit(1);
    }
}