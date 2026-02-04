#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef double doublereal;
typedef int integer;

doublereal *d__;
doublereal *vf;
doublereal *vfw;
doublereal *vl;
doublereal *vlw;
doublereal *dsigma;
integer *idxp;
integer i__1;
integer j;
integer jp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024 / sizeof(doublereal); // ~64MB for arrays of doublereal
    i__1 = (integer)data_size;

    d__ = (doublereal*)calloc(data_size, sizeof(doublereal));
    vf = (doublereal*)calloc(data_size, sizeof(doublereal));
    vfw = (doublereal*)calloc(data_size, sizeof(doublereal));
    vl = (doublereal*)calloc(data_size, sizeof(doublereal));
    vlw = (doublereal*)calloc(data_size, sizeof(doublereal));
    dsigma = (doublereal*)calloc(data_size, sizeof(doublereal));
    idxp = (integer*)malloc(data_size * sizeof(integer));

    if (!d__ || !vf || !vfw || !vl || !vlw || !dsigma || !idxp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        d__[i] = (doublereal)(i + 1);
        vf[i] = (doublereal)(i * 0.5);
        vl[i] = (doublereal)(i * 0.25);
        idxp[i] = (integer)i;
    }

    for (integer i = 0; i <= i__1; ++i) {
        if (i >= (integer)data_size) break;
        if (idxp[i] >= (integer)data_size) idxp[i] = data_size - 1;
    }
}