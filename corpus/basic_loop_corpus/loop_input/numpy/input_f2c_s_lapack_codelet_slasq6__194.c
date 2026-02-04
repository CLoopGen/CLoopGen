#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;
typedef double doublereal;

integer *i0;
real *z__;
real *dmin__;
integer i__1;
real r__1;
real r__2;
real d__;
integer j4;
real emin;
real temp;
real safmin;

static integer _i0_storage;
static real _dmin_storage;
static real *_z_storage = NULL;
static size_t _z_size = 0;

void init_vars() {
    // Set scalar values
    safmin = 1e-37f;  // Typical value for safe minimum in single precision
    d__ = 1.0f;
    emin = 1.0f;
    temp = 1.0f;
    i__1 = 1048576;  // ~4MB of data in z__ (each iteration uses up to j+2, so need extra space)
    
    // Allocate z__ array with sufficient size: loop accesses j4+2 where j4 <= i__1 and j4 starts at *i0 << 2
    // Ensure j4 + 2 <= i__1 + 2, so we need at least i__1 + 3 elements (indexed from 1? but C is 0-based)
    // The indexing in loop: z__[j4 - 3], z__[j4], z__[j4+2] -> max index = i__1 + 2
    _z_size = i__1 + 4;
    _z_storage = (real *)calloc(_z_size, sizeof(real));
    if (!_z_storage) {
        exit(1);
    }

    // Initialize z__ content to avoid division by zero or underflow issues
    for (size_t i = 0; i < _z_size; ++i) {
        _z_storage[i] = 1.0f + 0.01f * (i & 0xFF);  // Small variation to prevent exact zeros
    }

    // Set pointer variables
    i0 = &_i0_storage;
    *i0 = 1;  // So j4 starts at 4

    z__ = _z_storage;
    dmin__ = &_dmin_storage;
    *dmin__ = 1.0f;

    // Initialize loop-carried scalars
    r__1 = 1.0f;
    r__2 = 1.0f;
}