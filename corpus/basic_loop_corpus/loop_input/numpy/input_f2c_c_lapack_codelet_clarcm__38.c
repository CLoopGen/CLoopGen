#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
singlecomplex *c__;
real *rwork;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
real r__1;
singlecomplex q__1;
integer i__;
integer j;
integer l;

void init_vars() {
    const integer data_size_mb = 64;
    const integer total_elements = (data_size_mb * (1 << 20)) / sizeof(real);
    
    m = (integer*)malloc(sizeof(integer));
    *m = sqrt(total_elements / 2);
    if (*m < 1) *m = 1;
    
    c_dim1 = *m;
    i__1 = *m;
    l = *m;
    
    c__ = (singlecomplex*)calloc((*m + 1) * (i__1 + 1), sizeof(singlecomplex));
    rwork = (real*)calloc(l + (i__1 - 1) * *m + *m, sizeof(real));
    
    for (integer idx = 0; idx < (*m + 1) * (i__1 + 1); ++idx) {
        c__[idx].r = sinf(idx);
        c__[idx].i = cosf(idx);
    }
    
    for (integer idx = 0; idx < l + (i__1 - 1) * *m + *m; ++idx) {
        rwork[idx] = cosf(idx * 0.1f);
    }
}