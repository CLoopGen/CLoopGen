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

integer n_storage = 1024;
integer ihi_storage = 512;
integer i_1_storage = 1024;
integer i_2_storage;
integer i_3_storage;
integer i__ = 0;
integer j = 0;

integer *n = &n_storage;
integer *ihi = &ihi_storage;
integer *i__1 = &i_1_storage;
integer *i__2 = &i_2_storage;
integer *i__3 = &i_3_storage;

integer a_dim1 = 1024;

doublecomplex *a = NULL;

void init_vars() {
    const size_t total_size = (size_t)n_storage * (size_t)n_storage;
    a = (doublecomplex*)calloc(total_size, sizeof(doublecomplex));
    if (!a) {
        exit(1);
    }
}