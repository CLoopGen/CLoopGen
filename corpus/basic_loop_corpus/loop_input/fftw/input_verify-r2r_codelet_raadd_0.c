#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double bench_real;
typedef bench_real R;

R *c;
R *a;
R *b;
int n;
int i;

void init_vars() {
    n = 16777216;  // 16M elements -> ~128 MB of data (16M * 8 bytes per double * 3 arrays)
    size_t size = n * sizeof(R);

    a = (R*)aligned_alloc(32, size);
    b = (R*)aligned_alloc(32, size);
    c = (R*)aligned_alloc(32, size);

    for (i = 0; i < n; ++i) {
        a[i] = (R)(i % 100) / 10.0;
        b[i] = (R)((i + 1) % 100) / 10.0;
        c[i] = 0.0;
    }

    i = 0;
}