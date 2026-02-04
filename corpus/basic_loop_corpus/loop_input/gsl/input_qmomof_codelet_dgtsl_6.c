#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t n = 1 << 24; // Approximately 256MB of data for double arrays (3 arrays: b, d, e, c)
double *c;
double *d;
double *e;
double *b;
size_t k;

void init_vars() {
    c = (double *)aligned_alloc(32, n * sizeof(double));
    d = (double *)aligned_alloc(32, n * sizeof(double));
    e = (double *)aligned_alloc(32, n * sizeof(double));
    b = (double *)aligned_alloc(32, n * sizeof(double));

    if (!c || !d || !e || !b) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < n; i++) {
        c[i] = 1.0 + i % 100;
        d[i] = 0.1 * (i % 90 + 10);
        e[i] = 0.05 * (i % 80 + 20);
        b[i] = 100.0 + i;
    }

    k = n;
}