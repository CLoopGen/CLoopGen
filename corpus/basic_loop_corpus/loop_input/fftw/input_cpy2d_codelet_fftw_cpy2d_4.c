#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

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
INT vl;
INT i0;
INT i1;
INT v;

void init_vars() {
    n0 = 256;
    n1 = 256;
    vl = 4;

    is0 = n1 * vl;
    is1 = vl;
    os0 = n1 * vl;
    os1 = vl;

    size_t total_size = (size_t)n0 * n1 * vl * sizeof(R);

    I = (R*)aligned_alloc(32, total_size);
    O = (R*)aligned_alloc(32, total_size);

    for (size_t i = 0; i < total_size / sizeof(R); ++i) {
        I[i] = (R)(i & 0xFF);
        O[i] = 0.0;
    }

    i0 = 0;
    i1 = 0;
    v = 0;
}