#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <time.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *d__;
real *e;
integer i__1;
real r__1;
real r__2;
real r__3;
integer i__;
real sigmx;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB for two arrays of float
    d__ = (real*)aligned_alloc(32, data_size * sizeof(real));
    e = (real*)aligned_alloc(32, data_size * sizeof(real));
    
    if (!d__ || !e) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        d__[i] = (real)(drand48() * 2.0 - 1.0); // Random in [-1, 1]
        e[i] = (real)(drand48() * 2.0 - 1.0);
    }

    i__1 = (integer)data_size - 1; // Ensure we don't exceed array bounds
    sigmx = 0.0f;
    r__1 = 0.0f;
    r__2 = 0.0f;
    r__3 = 0.0f;
    i__ = 1;
}