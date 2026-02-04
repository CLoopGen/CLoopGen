#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double bench_real;
typedef bench_real bench_complex[2];
typedef bench_complex C;

C *c = NULL;
C *a = NULL;
C *b = NULL;
int n = 0;
int i = 0;

void init_vars() {
    size_t data_size = 1 << 24; // ~16M complex numbers, ~256MB total for 3 arrays
    n = (int)(data_size / sizeof(C));

    a = (C*)aligned_alloc(32, n * sizeof(C));
    b = (C*)aligned_alloc(32, n * sizeof(C));
    c = (C*)aligned_alloc(32, n * sizeof(C));

    if (!a || !b || !c) {
        exit(1);
    }

    for (int idx = 0; idx < n; ++idx) {
        a[idx][0] = (bench_real)(idx % 123);
        a[idx][1] = (bench_real)(idx % 456);
        b[idx][0] = (bench_real)(idx % 789);
        b[idx][1] = (bench_real)(idx % 101);
    }
}