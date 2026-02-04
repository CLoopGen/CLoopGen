#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *d__ = NULL;
real *z__ = NULL;
integer i__ = 0;
real dscale[3];
real sclfac;
real zscale[3];

void init_vars() {
    const size_t data_size = 1 << 20; // ~4MB total (each array ~2MB), floats
    d__ = (real*)aligned_alloc(32, (data_size + 1) * sizeof(real));
    z__ = (real*)aligned_alloc(32, (data_size + 1) * sizeof(real));

    if (!d__ || !z__) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i <= data_size; ++i) {
        d__[i] = sinf(i * 0.01f);
        z__[i] = cosf(i * 0.01f);
    }

    sclfac = 1.5f;

    i__ = 1;

    dscale[0] = dscale[1] = dscale[2] = 0.0f;
    zscale[0] = zscale[1] = zscale[2] = 0.0f;
}