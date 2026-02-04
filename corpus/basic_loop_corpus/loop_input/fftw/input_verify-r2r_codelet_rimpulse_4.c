#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef double bench_real;
typedef bench_real R;

R *inA;
int N = 134217728; // 134217728 elements * 8 bytes = ~1024 MB, adjust to hit ~0.01 sec runtime
int i;

void init_vars() {
    inA = (R*)aligned_alloc(32, N * sizeof(R));
    if (!inA) {
        exit(1);
    }
}