#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
singlecomplex *alpha;
singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    const int size_m = 5000;
    const int size_j = 5000;

    m = (integer*)malloc(sizeof(integer));
    alpha = (singlecomplex*)malloc(sizeof(singlecomplex));
    a = (singlecomplex*)calloc((size_m + 1) * (size_j + 1), sizeof(singlecomplex));

    *m = size_m;
    i__1 = size_j;
    a_dim1 = size_m + 1;

    alpha->r = 1.5f;
    alpha->i = 0.8f;

    i__ = 0;
    j = 0;
    i__2 = 0;
    i__3 = 0;
}