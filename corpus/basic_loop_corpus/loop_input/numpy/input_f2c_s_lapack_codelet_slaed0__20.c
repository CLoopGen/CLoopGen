#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *d__ = NULL;
real *e = NULL;
integer *iwork = NULL;
integer i__1;
real r__1;
integer i__;
integer smm1;
integer submat;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements to target ~0.01 sec runtime

    d__ = (real*)calloc(data_size + 1, sizeof(real));
    e = (real*)calloc(data_size, sizeof(real));
    iwork = (integer*)malloc(data_size * sizeof(integer));

    for (size_t i = 0; i < data_size; ++i) {
        e[i] = (real)(rand() % 100) / 10.0f - 5.0f;
        iwork[i] = (integer)(rand() % (data_size - 2));
    }

    i__1 = (integer)data_size - 1;

    for (size_t i = 1; i <= i__1; ++i) {
        integer idx = iwork[i] + 1;
        if (idx >= 0 && idx < (long)data_size) {
            d__[idx] = (real)(rand() % 100) / 10.0f;
        }
        if (idx - 1 >= 0 && idx - 1 < (long)data_size) {
            d__[idx - 1] = (real)(rand() % 100) / 10.0f;
        }
    }
}