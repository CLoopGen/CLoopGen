#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * (1 << 20) / sizeof(real))

static integer static_i0;
static real static_tau;
static real static_dmin;
static real *static_z_array;

void init_vars() {
    static_i0 = 1;
    i0 = &static_i0;

    static_tau = 0.001f;
    tau = &static_tau;

    static_dmin = 1e30f;
    dmin__ = &static_dmin;

    i__1 = ARRAY_SIZE - 4;

    if (i__1 <= (static_i0 << 2)) {
        i__1 = (static_i0 << 2) + 4;
    }

    static_z_array = (real*)aligned_alloc(32, ARRAY_SIZE * sizeof(real));
    if (!static_z_array) {
        exit(1);
    }

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        static_z_array[i] = (real)(1.0f + 0.01f * (rand() % 100));
    }

    z__ = static_z_array;

    d__ = 1.5f;
    emin = 1e30f;
    temp = 0.0f;
    j4 = 0;
}