#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double bench_real;
typedef bench_real bench_complex[2];
typedef bench_complex C;

C *a = NULL;
int n = 0;
int c = 0;
int i = 0;

void init_vars() {
    n = 1 << 23; // Approximately 64 million elements, ~192 MB for complex doubles
    c = 1;       // Choose valid index within [0,1] for the second dimension
    a = (C*)aligned_alloc(32, n * sizeof(C));
    if (!a) {
        exit(1);
    }
    for (int j = 0; j < n; ++j) {
        a[j][0] = (bench_real)(j % 100);
        a[j][1] = (bench_real)((j + 1) % 100);
    }
}