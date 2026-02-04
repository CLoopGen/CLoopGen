#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef float real;
typedef double doublereal;

integer *i0;
real *z__;
real *tau;
real *dmin__;
integer i__1;
real r__1;
real d__;
integer j4;
real emin;
real temp;

#define ARRAY_SIZE (65536 * 4)  // ~1MB of data for z__ array (enough to run loop meaningfully)

static integer _i0_storage;
static real _tau_storage;
static real _dmin_storage;
static real _z_array[ARRAY_SIZE + 8];  // Extra padding to prevent out-of-bounds access

void init_vars() {
    // Initialize scalar pointers
    i0 = &_i0_storage;
    tau = &_tau_storage;
    dmin__ = &_dmin_storage;

    // Initialize arrays and scalars
    z__ = _z_array + 4;  // Shift base so we can safely access [j4-3] with j4 starting at *i0<<2

    *i0 = 4;  // So j4 starts at 16
    i__1 = ARRAY_SIZE - 8;  // Ensure j4 <= i__1 doesn't exceed bounds, max j4 = i__1 (multiple of 4)
    d__ = 1.0f;
    emin = INFINITY;
    *tau = 0.001f;
    *dmin__ = 1e30;

    // Initialize z__ array with non-zero values to avoid division by zero
    for (int i = 0; i < ARRAY_SIZE + 8; ++i) {
        _z_array[i] = 1.0f + 0.01f * (i % 100);
    }
}