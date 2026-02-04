#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *d__ = NULL;
real *z__ = NULL;
integer i__ = 0;
real dscale[3] = {0.0f, 0.0f, 0.0f};
real zscale[3] = {0.0f, 0.0f, 0.0f};

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data (~1M floats)

    d__ = (real*)aligned_alloc(32, data_size * sizeof(real));
    z__ = (real*)aligned_alloc(32, data_size * sizeof(real));

    if (!d__ || !z__) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        d__[i] = (real)(i % 1000) + 1.5f;
        z__[i] = (real)((i + 500) % 1000) + 2.5f;
    }
}