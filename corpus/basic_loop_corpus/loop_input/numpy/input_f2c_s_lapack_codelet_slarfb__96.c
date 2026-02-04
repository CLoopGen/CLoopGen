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

static real *c_data;
static real *work_data;
static integer k_value;

void init_vars() {
    i__1 = 200;
    lastc = 300;
    lastv = 400;
    k_value = 50;
    k = &k_value;

    c_dim1 = lastc;
    work_dim1 = i__1;

    size_t c_size = (size_t)lastc * (lastv - *k + i__1);
    size_t work_size = (size_t)lastc * i__1;

    c_data = (real*)calloc(c_size, sizeof(real));
    work_data = (real*)calloc(work_size, sizeof(real));

    if (!c_data || !work_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    c__ = c_data;
    work = work_data;
}