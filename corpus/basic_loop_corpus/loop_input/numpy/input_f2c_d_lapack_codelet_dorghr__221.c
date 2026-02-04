#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer n_storage = 1000;
integer ihi_storage = 500;
doublereal *a_storage;
integer a_dim1 = 1000;
integer i__1 = 800;
integer i__2;
integer i__;
integer j;

integer *n = &n_storage;
integer *ihi = &ihi_storage;
doublereal *a = NULL;

void init_vars() {
    a_storage = (doublereal *)calloc(a_dim1 * n_storage, sizeof(doublereal));
    a = a_storage;
}