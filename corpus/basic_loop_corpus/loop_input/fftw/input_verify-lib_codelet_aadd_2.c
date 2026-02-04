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
    size_t data_size = 1 << 24; // ~16 million complex numbers, ~192 MB total for a,b,c
    n = data_size;

    a = (C*)aligned_alloc(32, n * sizeof(C));
    b = (C*)aligned_alloc(32, n * sizeof(C));
    c = (C*)aligned_alloc(32, n * sizeof(C));

    for (int idx = 0; idx < n; ++idx) {
        a[idx][0] = (bench_real)(idx % 1234);
        a[idx][1] = (bench_real)(idx % 5678);
        b[idx][0] = (bench_real)(idx % 4321);
        b[idx][1] = (bench_real)(idx % 8765);
        c[idx][0] = 0.0;
        c[idx][1] = 0.0;
    }
}