#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *n;
doublereal *z__;
doublereal *delta;
doublereal *work;
integer i__1;
integer j;
doublereal phi;
doublereal dphi;
doublereal temp;
doublereal erretm;

static size_t array_size = 0;

void init_vars() {
    array_size = (size_t)(128 * 1024 * 1024 / sizeof(doublereal)); // ~128MB of data

    z__ = (doublereal*)calloc(array_size, sizeof(doublereal));
    delta = (doublereal*)calloc(array_size, sizeof(doublereal));
    work = (doublereal*)calloc(array_size, sizeof(doublereal));

    if (!z__ || !delta || !work) {
        exit(1);
    }

    for (size_t i = 0; i < array_size; ++i) {
        z__[i] = sin(i * 0.001);
        delta[i] = cos(i * 0.001) + 1.5;
        work[i] = 1.0 / (i + 10.0);
    }

    n = (integer*)malloc(sizeof(integer));
    if (!n) exit(1);
    *n = (integer)(array_size - 1);

    i__1 = 0;

    phi = 0.0;
    dphi = 0.0;
    temp = 0.0;
    erretm = 0.0;
}