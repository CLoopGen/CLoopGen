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
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    i__1 = 5000;
    c_dim1 = i__1 + 1;
    size_t total_size = (i__1 + 1) * (c_dim1 + 1);
    c__ = (singlecomplex*)calloc(total_size, sizeof(singlecomplex));
    if (!c__) {
        exit(1);
    }
}