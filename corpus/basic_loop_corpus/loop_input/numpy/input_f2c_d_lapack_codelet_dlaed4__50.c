#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;
typedef double doublereal;

integer *n;
doublereal *z__;
doublereal *delta;
integer i__1;
integer j;
doublereal phi;
doublereal dphi;
doublereal temp;
doublereal erretm;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(doublereal))

static doublereal z_local[DATA_SIZE];
static doublereal delta_local[DATA_SIZE];

void init_vars() {
    n = (integer*)malloc(sizeof(integer));
    *n = DATA_SIZE - 1;
    i__1 = 0;

    z__ = z_local;
    delta = delta_local;

    phi = 0.0;
    dphi = 0.0;
    temp = 0.0;
    erretm = 0.0;

    for (integer i = 0; i < DATA_SIZE; ++i) {
        z__[i] = (doublereal)(i + 1);
        delta[i] = (doublereal)(i + 1) + 0.1;
    }
}