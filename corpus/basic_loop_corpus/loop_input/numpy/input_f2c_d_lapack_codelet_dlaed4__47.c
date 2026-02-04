#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

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

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(doublereal)) // ~64MB of data

static doublereal z_local[DATA_SIZE];
static doublereal delta_local[DATA_SIZE];

void init_vars() {
    n = &((integer){DATA_SIZE});
    i__1 = 1;
    phi = 0.0;
    dphi = 0.0;
    erretm = 0.0;
    temp = 0.0;

    z__ = z_local;
    delta = delta_local;

    for (integer i = 0; i < DATA_SIZE; ++i) {
        z__[i] = sin(i);
        delta[i] = cos(i) + 1.1; // Avoid zero
    }
}