#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double bench_real;
typedef bench_real bench_complex[2];

bench_complex *A;
int n;
bench_complex x;
int i;

void init_vars() {
    n = 16777216; // 16M elements, ~256MB for A (16M * 16 bytes per complex double)
    A = (bench_complex*)aligned_alloc(32, n * sizeof(bench_complex));
    if (!A) {
        exit(1);
    }

    x[0] = 1.5;
    x[1] = -0.8;

    for (i = 0; i < n; ++i) {
        A[i][0] = 0.0;
        A[i][1] = 0.0;
    }
}