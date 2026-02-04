#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *m;
doublecomplex *c__;
doublereal *rwork;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
doublereal d__1;
doublecomplex z__1;
integer i__;
integer j;
integer l;

void init_vars() {
    const integer data_size_mb = 64;
    const integer total_elements = (data_size_mb * (1 << 20)) / sizeof(doublereal);
    
    m = (integer*)malloc(sizeof(integer));
    *m = sqrt(total_elements / 2.0);
    if (*m < 1) *m = 1;

    c_dim1 = *m;
    i__1 = (total_elements / *m) > 1 ? total_elements / *m : 1;
    l = 1;

    size_t c_size = (i__1 + 1) * (c_dim1 + 1);
    c__ = (doublecomplex*)calloc(c_size, sizeof(doublecomplex));

    size_t rwork_size = l + (i__1 - 1) * *m + *m;
    rwork = (doublereal*)malloc(rwork_size * sizeof(doublereal));

    for (size_t idx = 0; idx < rwork_size; ++idx) {
        rwork[idx] = sin(idx * 0.1);
    }

    for (size_t idx = 0; idx < c_size; ++idx) {
        c__[idx].r = cos(idx * 0.1);
        c__[idx].i = sin(idx * 0.1);
    }
}