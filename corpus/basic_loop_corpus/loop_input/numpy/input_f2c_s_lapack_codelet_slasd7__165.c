#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef float real;
typedef int integer;

real *d__;
real *z__;
real *zw;
real *vf;
real *vfw;
real *vl;
real *vlw;
real *dsigma;
integer *idxq;
integer i__1;
integer i__;

void init_vars() {
    const uint64_t data_size = 64 * 1024 * 1024; 

    i__1 = (integer)(data_size / sizeof(real));
    
    d__     = (real*)    calloc(i__1 + 1, sizeof(real));
    z__     = (real*)    calloc(i__1 + 1, sizeof(real));
    zw      = (real*)    calloc(i__1 + 1, sizeof(real));
    vf      = (real*)    calloc(i__1 + 1, sizeof(real));
    vfw     = (real*)    calloc(i__1 + 1, sizeof(real));
    vl      = (real*)    calloc(i__1 + 1, sizeof(real));
    vlw     = (real*)    calloc(i__1 + 1, sizeof(real));
    dsigma  = (real*)    calloc(i__1 + 1, sizeof(real));
    idxq    = (integer*) calloc(i__1 + 1, sizeof(integer));

    for (integer i = 1; i <= i__1; ++i) {
        idxq[i] = (rand() % i__1) + 1;
    }

    for (integer i = 1; i <= i__1; ++i) {
        d__[i] = (real)(rand()) / RAND_MAX;
        z__[i] = (real)(rand()) / RAND_MAX;
        vf[i] = (real)(rand()) / RAND_MAX;
        vl[i] = (real)(rand()) / RAND_MAX;
    }
}