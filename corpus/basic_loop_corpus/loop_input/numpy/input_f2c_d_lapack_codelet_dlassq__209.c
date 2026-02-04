#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *x;
doublereal *scale;
doublereal *sumsq;
integer i__1;
integer i__2;
doublereal d__1;
integer ix;
doublereal absxi;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(doublereal))

static doublereal internal_x[DATA_SIZE];
static doublereal internal_scale;
static doublereal internal_sumsq;

void init_vars() {
    x = internal_x;
    scale = &internal_scale;
    sumsq = &internal_sumsq;

    i__1 = DATA_SIZE - 1;
    i__2 = 1;

    d__1 = 0.0;
    ix = 0;
    absxi = 0.0;

    internal_scale = 1.0;
    internal_sumsq = 1.0;

    for (int i = 0; i < DATA_SIZE; ++i) {
        x[i] = (doublereal)(rand() % 1000) / 100.0;
        if (rand() % 10 == 0) {
            x[i] *= -1;
        }
    }

    x[0] = 1.0;
}