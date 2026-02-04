#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;
typedef double doublereal;

integer *n;
real *a;
real *work;
integer a_dim1;
integer i__1;
integer i__2;
real r__1;
integer i__;
integer j;
real sum;
real absa;
real value;

static real a_data[2048 * 2048];
static real work_data[2048];

void init_vars() {
    const int size = 2048;
    a_dim1 = size;
    n = (integer*)&size;
    a = a_data;
    work = work_data;
    i__1 = size;
    i__2 = size;
    r__1 = 0.0f;
    i__ = 0;
    j = 0;
    sum = 0.0f;
    absa = 0.0f;
    value = 0.0f;

    for (int idx = 0; idx < size * size; ++idx) {
        a_data[idx] = (real)(idx % 127 - 64);
    }
    for (int idx = 0; idx < size; ++idx) {
        work_data[idx] = (real)(idx % 50);
    }
}