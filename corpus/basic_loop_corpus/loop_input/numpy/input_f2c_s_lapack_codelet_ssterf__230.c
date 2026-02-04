#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *d__;
real *e;
integer i__1;
real c__;
integer i__;
integer m;
real p;
real r__;
real s;
real bb;
real oldc;
real alpha;
real sigma;
real oldgam;

static real gamma_var;  // Renamed to avoid conflict with math.h gamma
real *gamma = &gamma_var;

static real d_storage[262144];  // ~1MB for d__ (262144 elements * 4 bytes)
static real e_storage[262144];  // ~1MB for e

void init_vars() {
    m = 262143;  // Size such that loop runs from m-1 down to i__1
    i__1 = 0;
    i__ = 0;
    p = 1.0f;
    c__ = 1.0f;
    sigma = 0.5f;
    oldgam = 0.0f;
    s = 1.0f;

    d__ = d_storage;
    e = e_storage;

    for (int i = 0; i <= m; ++i) {
        d__[i] = 1.0f + (i * 0.001f);
        e[i] = 0.5f + ((m - i) * 0.0001f);
    }

    *gamma = 0.5f;
}