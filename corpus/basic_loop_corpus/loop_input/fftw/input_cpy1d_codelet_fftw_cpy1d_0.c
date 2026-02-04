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

void init_vars() {
    const size_t data_size = 16777216; // 128 MB of data (16M doubles)
    n0 = data_size;
    is0 = 1;
    os0 = 1;

    I = (R*)aligned_alloc(32, data_size * sizeof(R));
    O = (R*)aligned_alloc(32, data_size * sizeof(R));

    for (size_t i = 0; i < data_size; ++i) {
        I[i] = (R)(i % 1000) + 0.5;
        O[i] = 0.0;
    }
}