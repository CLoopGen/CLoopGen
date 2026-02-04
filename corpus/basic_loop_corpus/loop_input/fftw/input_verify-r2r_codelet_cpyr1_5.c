#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double bench_real;
typedef bench_real R;

int n;
R *in;
int is;
R *out;
int os;
R scale;
int i;

void loop();

void init_vars() {
    n = 1 << 20; // 1 million elements, ~8MB for input and output (double precision)
    is = 1;
    os = 1;
    scale = 1.5;

    in = (R*)aligned_alloc(32, n * sizeof(R));
    out = (R*)aligned_alloc(32, n * sizeof(R));

    if (!in || !out) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < n; ++j) {
        in[j] = (R)(j % 1000) + 0.5;
        out[j] = 0.0;
    }
}