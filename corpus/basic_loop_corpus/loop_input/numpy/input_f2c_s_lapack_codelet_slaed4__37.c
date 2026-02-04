#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *i__;
real *d__;
real *delta;
integer i__1;
integer j;
real midpt;

static integer _i_val;
static real *_d_arr;
static real *_delta_arr;
static const size_t DATA_SIZE_MB = 64;
static const size_t ELEMENTS_PER_MB = 1024 * 1024 / sizeof(real);
static size_t ARRAY_LEN;

void init_vars() {
    ARRAY_LEN = DATA_SIZE_MB * ELEMENTS_PER_MB;

    _d_arr = (real*)calloc(ARRAY_LEN + 1, sizeof(real));
    _delta_arr = (real*)calloc(ARRAY_LEN + 1, sizeof(real));
    if (!_d_arr || !_delta_arr) {
        exit(1);
    }

    for (size_t idx = 1; idx <= ARRAY_LEN; ++idx) {
        _d_arr[idx] = (real)(rand() % 1000) / 10.0f;
    }

    _i_val = rand() % ARRAY_LEN + 1;
    midpt = 50.0f;

    d__ = _d_arr;
    delta = _delta_arr;
    i__ = &_i_val;
    i__1 = (integer)ARRAY_LEN;
}