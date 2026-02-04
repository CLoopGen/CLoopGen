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

integer *m;
real *a;
singlecomplex *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;

void init_vars() {
    const integer size = 8192; 

    m = (integer*)malloc(sizeof(integer));
    *m = size;

    a_dim1 = size;
    b_dim1 = size;

    i__1 = size;

    a = (real*)aligned_alloc(32, sizeof(real) * (size + 1) * (size + 1));
    b = (singlecomplex*)aligned_alloc(32, sizeof(singlecomplex) * (size + 1) * (size + 1));

    for (integer idx = 0; idx <= size * size + size; ++idx) {
        if (idx < (size + 1) * (size + 1)) {
            a[idx] = (real)(idx % 1000) / 100.0f;
        }
        if (idx < (size + 1) * (size + 1)) {
            b[idx].r = 0.0f;
            b[idx].i = 0.0f;
        }
    }

    i__ = 0;
    j = 0;
    i__2 = 0;
    i__3 = 0;
    i__4 = 0;
}