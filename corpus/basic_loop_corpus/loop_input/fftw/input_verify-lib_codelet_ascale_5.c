#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef double bench_real;
typedef bench_real bench_complex[2];
typedef bench_complex C;
typedef bench_real R;

C *a;
bench_complex alpha;
int n;
int i;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // Aim for ~64MB to ensure ~0.01s runtime
    const size_t element_size = sizeof(C);
    n = target_bytes / element_size;

    a = (C*)aligned_alloc(32, n * sizeof(C));
    if (!a) {
        exit(1);
    }

    for (int idx = 0; idx < n; ++idx) {
        a[idx][0] = (bench_real)(idx % 127) / 10.0;
        a[idx][1] = (bench_real)((idx + 10) % 127) / 10.0;
    }

    alpha[0] = 0.8;
    alpha[1] = 0.6;

    i = 0;
}