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

doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;

void init_vars() {
    a_dim1 = 10000;
    i__1 = 10000;

    size_t array_size = (i__1 + a_dim1 + 1);
    a = (doublecomplex*)calloc(array_size, sizeof(doublecomplex));
    if (!a) {
        exit(1);
    }
}