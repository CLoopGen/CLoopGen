#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *d__;
integer *indxq;
real *z__;
real *dlamda;
real *w;
integer i__1;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256MB of total data (adjustable)
    
    i__1 = data_size;

    d__ = (real*)aligned_alloc(32, sizeof(real) * data_size);
    z__ = (real*)aligned_alloc(32, sizeof(real) * data_size);
    dlamda = (real*)aligned_alloc(32, sizeof(real) * (data_size + 1));
    w = (real*)aligned_alloc(32, sizeof(real) * (data_size + 1));
    indxq = (integer*)aligned_alloc(32, sizeof(integer) * (data_size + 1));

    for (size_t i = 1; i <= data_size; ++i) {
        d__[i] = (real)(i * 1.5f + 1.0f);
        z__[i] = (real)(i * 0.75f - 0.5f);
        indxq[i] = rand() % data_size + 1;
    }

    for (size_t i = 1; i <= data_size + 1; ++i) {
        dlamda[i] = 0.0f;
        w[i] = 0.0f;
    }
}