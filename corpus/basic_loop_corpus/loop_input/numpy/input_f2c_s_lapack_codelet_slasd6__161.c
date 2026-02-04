#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
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
    const size_t data_size_bytes = 64 * 1024 * 1024; // ~64 MB for sufficient runtime (~0.01 sec on modern CPU)
    const size_t num_elements = data_size_bytes / sizeof(real);
    
    d__ = (real*)aligned_alloc(32, num_elements * sizeof(real));
    if (!d__) {
        exit(1);
    }

    i__1 = (integer)(num_elements - 1); // ensure index bounds: i__ from 1 to i__1
    i__ = 1;

    // Initialize array with random float values centered around zero
    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx <= i__1; ++idx) {
        d__[idx] = (real)((double)rand() / RAND_MAX * 2.0 - 1.0) * 1000.0f; // range [-1000, 1000]
    }

    // Initialize orgnrm to a small value to ensure it gets updated in the loop
    orgnrm = 0.0f;
}