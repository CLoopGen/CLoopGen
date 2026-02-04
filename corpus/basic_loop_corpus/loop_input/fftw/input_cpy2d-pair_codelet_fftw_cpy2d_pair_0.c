#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;

R *I0;
R *I1;
R *O0;
R *O1;
INT n0 = 512;
INT is0 = 1;
INT os0 = 1;
INT n1 = 512;
INT is1 = 512;
INT os1 = 512;
INT i0;
INT i1;

void init_vars() {
    size_t total_size = (size_t)n0 * (size_t)n1 * sizeof(R);

    I0 = (R*)aligned_alloc(64, total_size);
    I1 = (R*)aligned_alloc(64, total_size);
    O0 = (R*)aligned_alloc(64, total_size);
    O1 = (R*)aligned_alloc(64, total_size);

    if (!I0 || !I1 || !O0 || !O1) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < (size_t)n0 * n1; ++i) {
        I0[i] = (R)(i & 255);
        I1[i] = (R)((i + 1) & 255);
        O0[i] = 0.0;
        O1[i] = 0.0;
    }
}