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
    const size_t data_size = 64 * 1024 * 1024; // ~64 MB of input data
    const INT num_elements = data_size / sizeof(R);

    R *input_data = (R*)aligned_alloc(32, data_size);
    R *output_data = (R*)aligned_alloc(32, data_size);

    for (INT i = 0; i < num_elements; ++i) {
        input_data[i] = (R)(i & 0xFF);
    }

    I = input_data;
    O = output_data;
    n0 = num_elements / 4;
    is0 = 1;
    os0 = 1;
}