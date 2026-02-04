#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *work;
integer i__1;
real r__1;
real r__2;
integer i__;
real value;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of data for ~0.01 sec runtime estimate
    work = (real*)aligned_alloc(32, data_size * sizeof(real));
    if (!work) exit(1);

    for (size_t i = 0; i < data_size; ++i) {
        work[i] = (real)(drand48() * 2.0 - 1.0); // random values between -1 and 1
    }

    i__1 = (integer)(data_size - 1); // ensure i__ from 1 to i__1 accesses valid indices
    value = (real)-1.0;
    r__1 = 0.0;
    r__2 = 0.0;
    i__ = 0;
}