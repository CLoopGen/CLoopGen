#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *d__;
real *z__;
real *dlamda;
real *w;
integer *indx;
integer i__1;
integer i__;

static real *d_internal;
static real *z_internal;
static real *dlamda_internal;
static real *w_internal;
static integer *indx_internal;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of total data (adjustable)
    const size_t n = data_size / (sizeof(real) * 4 + sizeof(integer)); // balance across arrays

    d_internal = (real*)calloc(n + 1, sizeof(real));
    z_internal = (real*)calloc(n + 1, sizeof(real));
    dlamda_internal = (real*)malloc((n + 1) * sizeof(real));
    w_internal = (real*)malloc((n + 1) * sizeof(real));
    indx_internal = (integer*)malloc((n + 1) * sizeof(integer));

    if (!d_internal || !z_internal || !dlamda_internal || !w_internal || !indx_internal) {
        exit(1);
    }

    for (size_t i = 1; i <= n; ++i) {
        dlamda_internal[i] = sinf((float)i);
        w_internal[i] = cosf((float)i);
        indx_internal[i] = rand() % n + 1;
    }

    d__ = d_internal;
    z__ = z_internal;
    dlamda = dlamda_internal;
    w = w_internal;
    indx = indx_internal;
    i__1 = (integer)n;
    i__ = 1;
}