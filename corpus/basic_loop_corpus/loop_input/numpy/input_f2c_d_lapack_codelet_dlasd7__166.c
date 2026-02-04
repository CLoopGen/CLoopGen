#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef double doublereal;
typedef int integer;

doublereal *d__ = NULL;
doublereal *z__ = NULL;
doublereal *zw = NULL;
doublereal *vf = NULL;
doublereal *vfw = NULL;
doublereal *vl = NULL;
doublereal *vlw = NULL;
doublereal *dsigma = NULL;
integer *idx = NULL;
integer i__1 = 0;
integer i__ = 0;
integer idxi = 0;

#define DATA_SIZE 65536

void init_vars() {
    i__1 = DATA_SIZE;

    d__ = (doublereal*)calloc(DATA_SIZE + 1, sizeof(doublereal));
    z__ = (doublereal*)calloc(DATA_SIZE + 1, sizeof(doublereal));
    zw = (doublereal*)calloc(DATA_SIZE + 1, sizeof(doublereal));
    vf = (doublereal*)calloc(DATA_SIZE + 1, sizeof(doublereal));
    vfw = (doublereal*)calloc(DATA_SIZE + 1, sizeof(doublereal));
    vl = (doublereal*)calloc(DATA_SIZE + 1, sizeof(doublereal));
    vlw = (doublereal*)calloc(DATA_SIZE + 1, sizeof(doublereal));
    dsigma = (doublereal*)calloc(DATA_SIZE + 1, sizeof(doublereal));
    idx = (integer*)malloc((DATA_SIZE + 1) * sizeof(integer));

    for (int i = 0; i <= DATA_SIZE; ++i) {
        dsigma[i] = (doublereal)(i * 1.5);
        zw[i] = (doublereal)(i * 2.5);
        vfw[i] = (doublereal)(i * 3.5);
        vlw[i] = (doublereal)(i * 4.5);
        idx[i] = (i == 0) ? 0 : (rand() % i);
    }

    idx[1] = 0;
    for (int i = 2; i <= DATA_SIZE; ++i) {
        if (idx[i] >= DATA_SIZE) idx[i] = idx[i] % DATA_SIZE;
    }
}