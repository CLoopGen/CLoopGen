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
    N = 134217728 / sizeof(R);  // ~134M elements to target ~0.01s runtime with 1GB/s memset-like speed
    I = (R*)aligned_alloc(64, N * sizeof(R));
    if (!I) {
        exit(1);
    }
}