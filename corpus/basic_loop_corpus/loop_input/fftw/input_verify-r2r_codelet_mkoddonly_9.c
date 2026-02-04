#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double bench_real;
typedef bench_real bench_complex[2];
typedef bench_complex C;

C *a;
int n = 0;
int i = 0;

void init_vars() {
    size_t data_size = 1 << 24; // ~16 million elements, roughly 128MB for complex doubles
    n = (int)(data_size / sizeof(C));
    a = aligned_alloc(32, n * sizeof(C));
    if (!a) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}