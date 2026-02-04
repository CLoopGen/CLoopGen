#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

doublecomplex *beta;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t total_elements = (data_size_mb * (1 << 20)) / sizeof(doublecomplex);

    a = (doublecomplex*)calloc(total_elements, sizeof(doublecomplex));
    beta = (doublecomplex*)malloc(sizeof(doublecomplex));

    beta->r = 1.5;
    beta->i = -0.8;

    a_dim1 = (integer)(total_elements > 10000 ? 10000 : total_elements);
    i__1 = (integer)(total_elements / a_dim1);
    if (i__1 > a_dim1) i__1 = a_dim1;

    i__ = 0;
    i__2 = 0;
}