#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef double bench_real;
typedef bench_real R;

R *a;
R alpha;
int n;
int i;

void init_vars() {
    n = 16777216; // 16M elements, ~128MB for double
    alpha = 1.5;
    a = (R*)aligned_alloc(32, n * sizeof(R));
    if (!a) {
        exit(1);
    }
    for (int j = 0; j < n; ++j) {
        a[j] = (R)(j % 1024 + 1);
    }
}