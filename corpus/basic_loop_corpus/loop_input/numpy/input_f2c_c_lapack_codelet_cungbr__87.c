#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    a_dim1 = 4096;
    i__1 = 4096;

    size_t array_size = (size_t)(a_dim1 + 1) * (size_t)(i__1 + 1);
    a = (singlecomplex*)calloc(array_size, sizeof(singlecomplex));
    if (!a) {
        exit(1);
    }

    for (size_t idx = 0; idx < array_size; ++idx) {
        a[idx].r = (real)(idx % 100) / 10.0f;
        a[idx].i = (real)(idx % 75) / 10.0f;
    }
}