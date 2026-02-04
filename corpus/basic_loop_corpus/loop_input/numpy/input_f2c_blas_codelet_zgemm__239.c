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
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    const integer size_m = 4096;
    const integer size_n = 4096;

    m = (integer*)malloc(sizeof(integer));
    *m = size_m;

    c_dim1 = size_m;
    i__1 = size_n;

    size_t total_size = (size_t)(size_m + 1) * (size_n + 1);
    c__ = (doublecomplex*)calloc(total_size, sizeof(doublecomplex));

    i__ = 1;
    j = 1;
    i__2 = *m;
    i__3 = 1 + 1 * c_dim1;
}