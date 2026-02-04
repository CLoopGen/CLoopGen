#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;

R *I;
R *O;
INT n0;
INT is0;
INT os0;
INT n1;
INT is1;
INT os1;
INT i0;
INT i1;

void init_vars() {
    n0 = 512;
    n1 = 512;
    is0 = 1;
    is1 = 512;
    os0 = 1;
    os1 = 512;

    size_t total_size = (n0 * is0 + n1 * is1 + 2) * sizeof(R);
    I = (R*)aligned_alloc(32, total_size);
    O = (R*)aligned_alloc(32, total_size);

    for (size_t i = 0; i < (size_t)(n0 * is0 + n1 * is1 + 2); ++i) {
        I[i] = (R)(i & 0xFF);
    }

    i0 = 0;
    i1 = 0;
}