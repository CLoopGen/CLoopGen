#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *d__ = NULL;
integer i__1;
real r__1;
integer i__;
real orgnrm;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 MB of float data
    d__ = (real*)calloc(data_size, sizeof(real));
    if (!d__) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        d__[idx] = (real)(rand() % 2000 - 1000) / 10.0f; // Random values in [-100, 100]
    }

    i__1 = (integer)(data_size - 1); 
    orgnrm = 0.0f;
    i__ = 0;
}