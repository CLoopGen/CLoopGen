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
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for ~0.01s runtime estimate
    work = (real*)aligned_alloc(32, data_size * sizeof(real));
    if (!work) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        work[i] = (real)(rand() % 1000) / 10.0f;
    }

    i__1 = (integer)(data_size - 1); 
    value = 50.0f;
    r__1 = 0.0f;
    r__2 = 0.0f;
    i__ = 0;
}