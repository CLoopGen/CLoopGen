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

integer n_data = 1000;
integer *n = &n_data;

integer ihi_data = 800;
integer *ihi = &ihi_data;

integer a_dim1_data = 1000;
integer a_dim1 = 1000;

doublecomplex *a;

integer i__1 = 1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;

void init_vars() {
    const size_t total_size = (size_t)a_dim1_data * (size_t)n_data;
    a = (doublecomplex*)calloc(total_size, sizeof(doublecomplex));
    if (!a) {
        exit(1);
    }
}