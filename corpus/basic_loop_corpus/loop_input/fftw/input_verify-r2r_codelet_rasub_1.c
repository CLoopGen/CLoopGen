#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef double bench_real;
typedef bench_real R;

R *c;
R *a;
R *b;
int n;
int i;

void init_vars() {
    n = 16777216;  // 16M elements, ~128 MB total (3 arrays), targets ~0.01 sec on modern CPU

    a = (R*)aligned_alloc(32, n * sizeof(R));
    b = (R*)aligned_alloc(32, n * sizeof(R));
    c = (R*)aligned_alloc(32, n * sizeof(R));

    if (!a || !b || !c) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < n; ++j) {
        a[j] = (R)(j % 1000) + 1.0;
        b[j] = (R)((j * 7) % 1000) + 0.5;
    }
}