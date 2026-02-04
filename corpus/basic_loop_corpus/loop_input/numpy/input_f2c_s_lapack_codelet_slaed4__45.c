#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *n;
real *z__;
real *delta;
integer i__1;
integer j;
real phi;

static const size_t DATA_SIZE_MB = 64;
static const size_t ELEMENTS_PER_MB = (1 << 20) / sizeof(real);
static const size_t TOTAL_ELEMENTS = DATA_SIZE_MB * ELEMENTS_PER_MB;

static integer internal_n;
static real *internal_z__;
static real *internal_delta;

void init_vars() {
    internal_n = (integer)TOTAL_ELEMENTS;
    n = &internal_n;

    i__1 = 1;

    internal_z__ = (real*)calloc(TOTAL_ELEMENTS + 1, sizeof(real));
    z__ = internal_z__;

    internal_delta = (real*)calloc(TOTAL_ELEMENTS + 1, sizeof(real));
    delta = internal_delta;

    phi = 0.0f;

    for (size_t i = 1; i <= TOTAL_ELEMENTS; ++i) {
        internal_z__[i] = (real)(rand() % 100 - 50) / 10.0f;
        internal_delta[i] = (real)(rand() % 50 + 1) / 10.0f;
    }
}