#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

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
integer i__3;
integer i__4;
doublecomplex z__1;
integer i__;
integer j;
integer k1;
integer k3;
doublereal mul;

void init_vars() {
    const size_t total_size_mb = 64;
    const size_t element_size = sizeof(doublecomplex);
    const size_t total_elements = (total_size_mb * 1024 * 1024) / element_size;

    a_dim1 = (integer)sqrt((double)total_elements);
    i__1 = a_dim1 / 4;
    k1 = a_dim1 / 2;
    k3 = a_dim1;
    mul = 2.5;

    a = (doublecomplex*)calloc(total_elements, element_size);
    if (!a) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; ++idx) {
        a[idx].r = sin(idx);
        a[idx].i = cos(idx);
    }
}