#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *c__ = NULL;
singlecomplex *work = NULL;
integer c_dim1;
integer work_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
singlecomplex q__1;
integer i__;
integer j;
integer lastc;

void init_vars() {
    const int rows = 8000;
    const int cols = 4000;
    
    c_dim1 = rows;
    work_dim1 = rows;
    i__1 = cols;
    lastc = rows;

    size_t c_size = (rows + 1) * (cols + 1);
    size_t work_size = (rows + 1) * (cols + 1);

    c__ = (singlecomplex*)calloc(c_size, sizeof(singlecomplex));
    work = (singlecomplex*)calloc(work_size, sizeof(singlecomplex));

    for (size_t idx = 0; idx < c_size; ++idx) {
        c__[idx].r = (real)(idx % 100) + 1.5f;
        c__[idx].i = (real)(idx % 75) + 0.8f;
    }

    for (size_t idx = 0; idx < work_size; ++idx) {
        work[idx].r = (real)(idx % 50) + 0.3f;
        work[idx].i = (real)(idx % 25) + 1.2f;
    }
}