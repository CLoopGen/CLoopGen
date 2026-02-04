#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *m;
doublereal *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    i__1 = 500;
    *m = 500;
    c_dim1 = 500 + 10;
    size_t c_size = (size_t)(i__1 + 1) * (size_t)(*m + 1);
    c__ = (doublereal*)calloc(c_size, sizeof(doublereal));
    if (!c__) {
        exit(1);
    }
}

static void __attribute__((constructor)) initialize() {
    m = (integer*)malloc(sizeof(integer));
    if (!m) exit(1);
    *m = 0;
    init_vars();
}