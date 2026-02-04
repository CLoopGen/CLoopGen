#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *k;
doublereal *c__;
doublereal *work;
integer c_dim1;
integer work_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer lastc;
integer lastv;

static doublereal *c_data = NULL;
static doublereal *work_data = NULL;
static integer k_value;

void init_vars() {
    lastv = 500;
    lastc = 500;
    i__1 = 400;
    work_dim1 = 400;
    c_dim1 = 600;

    k = &k_value;
    *k = 100;

    size_t c_size = (lastv - *k + i__1) * c_dim1 + lastc + 10;
    size_t work_size = (lastc) * work_dim1 + i__1 + 10;

    c_data = (doublereal*)calloc(c_size, sizeof(doublereal));
    work_data = (doublereal*)calloc(work_size, sizeof(doublereal));

    if (!c_data || !work_data) {
        exit(1);
    }

    c__ = c_data;
    work = work_data;
}