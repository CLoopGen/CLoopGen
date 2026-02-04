#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;
typedef int integer;

real *d__;
real *vf;
real *vfw;
real *vl;
real *vlw;
real *dsigma;
integer *idxp;
integer i__1;
integer j;
integer jp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024 / sizeof(real); // ~64MB of real data
    i__1 = (integer)data_size;

    d__ = (real*)calloc(data_size, sizeof(real));
    vf = (real*)calloc(data_size, sizeof(real));
    vl = (real*)calloc(data_size, sizeof(real));
    dsigma = (real*)calloc(data_size, sizeof(real));
    vfw = (real*)calloc(data_size, sizeof(real));
    vlw = (real*)calloc(data_size, sizeof(real));
    idxp = (integer*)malloc((data_size + 1) * sizeof(integer));

    for (size_t i = 0; i < data_size; ++i) {
        d__[i] = (real)(rand()) / RAND_MAX;
        vf[i] = (real)(rand()) / RAND_MAX;
        vl[i] = (real)(rand()) / RAND_MAX;
        idxp[i] = (integer)(rand() % data_size);
    }
    idxp[0] = 0;
}