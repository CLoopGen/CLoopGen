#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;

real *beta;
real *a;
integer a_dim1;
integer i__1;
integer i__;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB of data
    a_dim1 = (integer)sqrt(data_size / sizeof(real));
    i__1 = a_dim1;

    a = (real*)calloc((i__1 + 1) * (a_dim1 + 1), sizeof(real));
    if (!a) {
        exit(1);
    }

    beta = (real*)malloc(sizeof(real));
    if (!beta) {
        exit(1);
    }
    *beta = 3.14159f;
}