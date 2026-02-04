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
real *dmin__;
integer i__1;
real r__1;
real r__2;
real d__;
integer j4;
real emin;
real temp;
real safmin;

static integer static_i0;
static real static_dmin;
static real *static_z;

void init_vars() {
    safmin = 1e-38f;
    emin = 1e30f;
    d__ = 1.0f;
    temp = 0.0f;
    r__1 = 0.0f;
    r__2 = 0.0f;

    static_i0 = 1;
    i__1 = 65536; 

    i0 = &static_i0;
    dmin__ = &static_dmin;
    *dmin__ = 1e30f;

    static_z = (real*)aligned_alloc(16, sizeof(real) * (i__1 + 4));
    if (!static_z) exit(1);

    z__ = static_z;

    for (integer i = 0; i < i__1 + 4; ++i) {
        z__[i] = 1.0f + 0.01f * (i & 31);
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}