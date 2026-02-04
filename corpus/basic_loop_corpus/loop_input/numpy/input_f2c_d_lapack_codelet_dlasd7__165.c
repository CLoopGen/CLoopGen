#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef double doublereal;
typedef int integer;

doublereal *d__;
doublereal *z__;
doublereal *zw;
doublereal *vf;
doublereal *vfw;
doublereal *vl;
doublereal *vlw;
doublereal *dsigma;
integer *idxq;
integer i__1;
integer i__;

#define DATA_SIZE (64 << 20) / sizeof(doublereal)

void init_vars() {
    d__ = (doublereal*)calloc(DATA_SIZE, sizeof(doublereal));
    z__ = (doublereal*)calloc(DATA_SIZE, sizeof(doublereal));
    zw = (doublereal*)calloc(DATA_SIZE, sizeof(doublereal));
    vf = (doublereal*)calloc(DATA_SIZE, sizeof(doublereal));
    vfw = (doublereal*)calloc(DATA_SIZE, sizeof(doublereal));
    vl = (doublereal*)calloc(DATA_SIZE, sizeof(doublereal));
    vlw = (doublereal*)calloc(DATA_SIZE, sizeof(doublereal));
    dsigma = (doublereal*)calloc(DATA_SIZE, sizeof(doublereal));
    idxq = (integer*)malloc(DATA_SIZE * sizeof(integer));

    for (size_t i = 0; i < DATA_SIZE; ++i) {
        d__[i] = rand() / (double)RAND_MAX;
        z__[i] = rand() / (double)RAND_MAX;
        vf[i] = rand() / (double)RAND_MAX;
        vl[i] = rand() / (double)RAND_MAX;
        idxq[i] = rand() % (DATA_SIZE - 1) + 1;
    }

    idxq[0] = 0;
    for (size_t i = 1; i < DATA_SIZE; ++i) {
        if ((size_t)idxq[i] >= DATA_SIZE) {
            idxq[i] = i % (DATA_SIZE - 1) + 1;
        }
    }

    i__1 = DATA_SIZE - 1;
    i__ = 2;
}