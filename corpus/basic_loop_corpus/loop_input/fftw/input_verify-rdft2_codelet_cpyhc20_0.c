#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double bench_real;
typedef bench_real R;

int i;
int n = 134217728; // 128M elements -> ~1GB total data (ensures loop runs ~0.01s)
int as = 1;
R *ra;
R *ia;
R *rb;
R *ib;

void init_vars() {
    ra = (R*)aligned_alloc(32, n * sizeof(R));
    ia = (R*)aligned_alloc(32, n * sizeof(R));
    rb = (R*)aligned_alloc(32, (n + 1) * sizeof(R)); // slightly larger to avoid overflow
    ib = (R*)aligned_alloc(32, (n + 1) * sizeof(R));

    for (int j = 0; j < n; ++j) {
        ra[j] = (R)(j * 1.0);
        ia[j] = (R)(j * 0.5);
    }
}