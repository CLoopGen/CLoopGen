#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;

INT n = 1 << 24; // Approximately 128MB of data (64M doubles), tuned for ~0.01s runtime

R *r;
R *rio;
R *iio;
INT os = 1;
INT i;

void init_vars() {
    r = (R*)aligned_alloc(64, n * sizeof(R));
    rio = (R*)aligned_alloc(64, n * sizeof(R));
    iio = (R*)aligned_alloc(64, n * sizeof(R));

    if (!r || !rio || !iio) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (INT idx = 0; idx < n; ++idx) {
        r[idx] = (R)(idx * 1.5);
        rio[idx] = 0.0;
        iio[idx] = 0.0;
    }

    // Ensure loop condition `i + i < n` is safe: max i is (n-1)/2, so n-i >= (n+1)/2 > 0
}