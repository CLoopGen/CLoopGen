#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *n;
doublecomplex *t;
doublecomplex *work;
integer t_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;

void init_vars() {
    n = (integer*)malloc(sizeof(integer));
    *n = 10000;

    t_dim1 = *n + 1;
    i__1 = *n;

    size_t t_size = ((*n) + 1) * (t_dim1 + 1);
    t = (doublecomplex*)calloc(t_size, sizeof(doublecomplex));
    if (!t) exit(1);

    size_t work_size = *n + *n + 1;
    work = (doublecomplex*)calloc(work_size, sizeof(doublecomplex));
    if (!work) exit(1);
}