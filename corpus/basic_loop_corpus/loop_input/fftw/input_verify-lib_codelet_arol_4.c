#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double bench_real;
typedef bench_real bench_complex[2];
typedef bench_complex C;

C *b;
C *a;
int n = 512;
int nb = 4;
int na = 64;
int i;
int ib;
int ia;

void init_vars() {
    size_t total_size_a = (size_t)nb * n * na;
    size_t total_size_b = total_size_a;

    a = (C*)aligned_alloc(32, total_size_a * sizeof(C));
    b = (C*)aligned_alloc(32, total_size_b * sizeof(C));

    if (!a || !b) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size_a; ++idx) {
        a[idx][0] = (bench_real)(idx % 1000) + 0.5;
        a[idx][1] = (bench_real)((idx * 37) % 1000) + 0.25;
    }
    for (size_t idx = 0; idx < total_size_b; ++idx) {
        b[idx][0] = 0.0;
        b[idx][1] = 0.0;
    }
}