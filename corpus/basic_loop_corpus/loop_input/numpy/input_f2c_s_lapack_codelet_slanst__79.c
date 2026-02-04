#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *d__;
real *e;
integer i__1;
real r__1;
real r__2;
real r__3;
real r__4;
real r__5;
integer i__;
real anorm;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of total data (adjust as needed for timing)
    
    d__ = (real*)aligned_alloc(32, sizeof(real) * (data_size + 1));
    e = (real*)aligned_alloc(32, sizeof(real) * (data_size + 1));

    if (!d__ || !e) {
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx <= data_size; ++idx) {
        d__[idx] = (real)(drand48() * 2.0 - 1.0);
        e[idx] = (real)(drand48() * 2.0 - 1.0);
    }

    i__1 = (integer)data_size;
    anorm = (real)0.0;
    i__ = 1;

    r__1 = 0.0;
    r__2 = 0.0;
    r__3 = 0.0;
    r__4 = 0.0;
    r__5 = 0.0;
}