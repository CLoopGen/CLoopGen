#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *z__;
real *delta;
real *work;
integer i__1;
integer j;
real psi;
real dpsi;
real temp;
real erretm;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of total data (adjustable)
    const size_t num_elements = data_size / (3 * sizeof(real)); // Three arrays: z__, delta, work

    i__1 = (integer)num_elements;

    z__ = (real*)aligned_alloc(32, num_elements * sizeof(real));
    delta = (real*)aligned_alloc(32, num_elements * sizeof(real));
    work = (real*)aligned_alloc(32, num_elements * sizeof(real));

    for (size_t i = 0; i < num_elements; ++i) {
        z__[i] = (real)(rand() % 100) / 10.0f + 1.0f;
        delta[i] = (real)(rand() % 100) / 50.0f + 0.5f;
        work[i] = (real)(rand() % 100) / 20.0f + 0.8f;
    }

    psi = 0.0f;
    dpsi = 0.0f;
    temp = 0.0f;
    erretm = 0.0f;
    j = 0;
}