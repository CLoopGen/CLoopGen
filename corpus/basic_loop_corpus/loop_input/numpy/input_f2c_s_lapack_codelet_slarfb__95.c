#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *k;
real *c__;
real *work;
integer c_dim1;
integer work_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer lastc;
integer lastv;

void init_vars() {
    const size_t data_size = 1 << 20; // ~4MB of data (adjustable for timing)

    lastv = 1000;
    lastc = 1000;
    i__1 = 1000;
    c_dim1 = lastc;
    work_dim1 = i__1;

    k = (integer*)malloc(sizeof(integer));
    *k = 500;

    size_t c_size = (lastv - *k + i__1) * c_dim1 + lastc;
    if (c_size < (size_t)(lastv - *k + i__1 + lastc * c_dim1)) {
        c_size = (lastv - *k + i__1 + lastc * c_dim1);
    }
    c__ = (real*)calloc(c_size, sizeof(real));

    size_t work_size = lastc * work_dim1 + 1;
    work = (real*)calloc(work_size, sizeof(real));

    i__ = 1;
    j = 1;
}