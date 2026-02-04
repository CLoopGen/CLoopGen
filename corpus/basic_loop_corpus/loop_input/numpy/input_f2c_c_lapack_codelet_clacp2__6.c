#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
    const integer size = 8000;
    
    m = (integer*)malloc(sizeof(integer));
    *m = size;
    
    a_dim1 = size;
    b_dim1 = size;
    i__1 = size;
    
    a = (real*)calloc(size * size, sizeof(real));
    b = (singlecomplex*)calloc(size * size, sizeof(singlecomplex));
    
    for (integer idx = 0; idx < size * size; ++idx) {
        a[idx] = (real)(idx % 1000) / 10.0f;
    }
}