#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double bench_real;
typedef bench_real bench_complex[2];
typedef bench_complex C;

C *a = NULL;
int n;
int i;

void init_vars() {
    size_t data_size = 1 << 20; // Approximately 1MB of data: 2^20 elements
    n = data_size;
    a = (C*)calloc(n, sizeof(C));
    if (!a) {
        exit(1);
    }
}