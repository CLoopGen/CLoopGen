#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef R E;

INT n;
E *x;
R *w;
INT i;
E rr;
E ri;
E ir;
E ii;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // ~128MB of total input data
    const size_t num_x_elements = data_size / sizeof(E);
    const size_t num_w_elements = data_size / (2 * sizeof(R)); 

    x = (E*)aligned_alloc(32, num_x_elements * sizeof(E));
    w = (R*)aligned_alloc(32, num_w_elements * sizeof(R));

    for (size_t idx = 0; idx < num_x_elements; ++idx) {
        x[idx] = (E)(1.0 + (idx % 7)) / (1.0 + (idx % 3));
    }
    for (size_t idx = 0; idx < num_w_elements; ++idx) {
        w[idx] = (R)(1.0 + (idx % 5)) / (1.0 + (idx % 11));
    }

    n = (num_x_elements / 4) * 2; 
    if (num_w_elements < n / 2) {
        n = num_w_elements * 2;
    }

    rr = 0.0;
    ri = 0.0;
    ir = 0.0;
    ii = 0.0;
}