#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

const integer initial_m = 2048;
const integer initial_i__1 = 512;
const integer initial_a_dim1 = 2048;

integer *m;
singlecomplex *a;
integer a_dim1;
integer ret_val;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    m = (integer*)malloc(sizeof(integer));
    *m = initial_m;

    a_dim1 = initial_a_dim1;
    i__1 = initial_i__1;

    size_t total_elements = (size_t)(*m) * (size_t)a_dim1;
    a = (singlecomplex*)calloc(total_elements, sizeof(singlecomplex));

    if (!a) {
        exit(1);
    }

    ret_val = 0;
    i__2 = 0;
    i__ = 0;
    j = 0;

    for (integer idx = 0; idx < total_elements; ++idx) {
        a[idx].r = (real)(sin(idx) > 0.5 ? 0.0 : 1.0);
        a[idx].i = (real)(cos(idx) > 0.5 ? 0.0 : 1.0);
    }
}