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

integer *n;
integer *ihi;
singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    const integer size_n = 2048;
    const integer size_ihi = 100;
    const integer size_j_max = 150;

    n = (integer*)malloc(sizeof(integer));
    ihi = (integer*)malloc(sizeof(integer));
    n[0] = size_n;
    ihi[0] = size_ihi;
    i__1 = size_j_max;
    a_dim1 = size_n;

    a = (singlecomplex*)calloc((size_n + 1) * (size_j_max + 1), sizeof(singlecomplex));

    i__ = 0;
    j = 0;
    i__2 = 0;
    i__3 = 0;
}