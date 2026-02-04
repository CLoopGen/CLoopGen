#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double bench_real;
typedef bench_real bench_complex[2];
typedef bench_complex C;

C *c;
C *a;
int n = 131072; // ~2MB of data (131072 elements * 16 bytes per complex = 2,097,152 bytes)
int i;

void init_vars() {
    a = (C*)aligned_alloc(32, n * sizeof(C));
    c = (C*)aligned_alloc(32, n * sizeof(C));

    if (!a || !c) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < n; ++idx) {
        (a[idx])[0] = (bench_real)(idx % 1000) + 0.5;
        (a[idx])[1] = (bench_real)((idx + 1) % 1000) + 0.25;
        (c[idx])[0] = 0.0;
        (c[idx])[1] = 0.0;
    }
}