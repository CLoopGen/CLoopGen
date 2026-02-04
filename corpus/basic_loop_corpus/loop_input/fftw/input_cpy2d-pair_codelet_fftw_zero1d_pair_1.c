#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;

R *O0;
R *O1;
INT n0;
INT os0;
INT i0;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime (~0.01s)
    n0 = data_size / sizeof(R);
    os0 = 1; // ensures consecutive access; total elements = n0

    O0 = aligned_alloc(32, n0 * os0 * sizeof(R));
    O1 = aligned_alloc(32, n0 * os0 * sizeof(R));

    if (!O0 || !O1) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}