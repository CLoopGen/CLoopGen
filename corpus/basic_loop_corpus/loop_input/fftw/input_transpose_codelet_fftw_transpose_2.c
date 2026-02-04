#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef double R;
typedef ptrdiff_t INT;

R *I;
INT n = 512;
INT s0 = 2048;
INT s1 = 1;
INT vl = 4;
INT i0;
INT i1;
INT v;

void init_vars() {
    const size_t total_size = (size_t)n * (size_t)s0 * sizeof(R);
    I = aligned_alloc(32, total_size);
    if (!I) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (size_t i = 0; i < total_size / sizeof(R); ++i) {
        I[i] = sin(i * 0.01);
    }
}