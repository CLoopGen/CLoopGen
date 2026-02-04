#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *m;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // Aim for ~64 MB of data
    const size_t approx_elements = target_bytes / sizeof(doublecomplex);
    a_dim1 = (integer)sqrt(approx_elements);
    if (a_dim1 < 2) a_dim1 = 2;

    a = (doublecomplex*)calloc(a_dim1 * a_dim1, sizeof(doublecomplex));
    if (!a) exit(1);

    m = (integer*)malloc(sizeof(integer));
    if (!m) exit(1);
    *m = a_dim1;

    i__1 = 0;
    i__2 = 0;
    i__3 = 0;
    i__ = 0;
    j = 0;
}