#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;

real *beta;
real *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // Aim for ~64 MB of data
    const size_t side_length = (size_t)sqrt(target_bytes / sizeof(real));
    
    c_dim1 = side_length;
    i__1 = (integer)side_length;
    
    beta = (real*)malloc(sizeof(real));
    *beta = 1.5f;
    
    size_t c_size = (side_length + 1) * (side_length + 1); // 1-based indexing, j up to side_length, i up to j
    c__ = (real*)calloc(c_size, sizeof(real));
}

// Definitions of external symbols
real *beta = NULL;
real *c__ = NULL;
integer c_dim1 = 0;
integer i__1 = 0;
integer i__2 = 0;
integer i__ = 0;
integer j = 0;