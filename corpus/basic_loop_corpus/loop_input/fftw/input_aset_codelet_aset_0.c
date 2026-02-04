#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double bench_real;

bench_real *A;
int n;
bench_real x;
int i;

void init_vars() {
    n = 32000000; // Approximately 256 MB of data (32e6 * 8 bytes per double)
    A = (bench_real*)aligned_alloc(32, n * sizeof(bench_real));
    if (!A) {
        exit(1);
    }
    x = 3.14159;
    i = 0;
}