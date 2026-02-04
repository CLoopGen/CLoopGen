#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double bench_real;
typedef bench_real bench_complex[2];
typedef bench_complex C;

C *A = NULL;
int n = 0;
int i = 0;

void init_vars() {
    n = 13421772;  // Approximately 200 MB of data (13421772 * 16 bytes per C) to target ~0.01s on modern CPUs
    A = (C*)aligned_alloc(32, n * sizeof(C));
    if (!A) {
        exit(1);
    }
    for (int j = 0; j < n; ++j) {
        (A[j])[0] = 0.0;
        (A[j])[1] = 1.0;
    }
}