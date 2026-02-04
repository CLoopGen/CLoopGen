#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *n;
real *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

static real *c__buf = NULL;
static const integer default_n = 5000;

void init_vars() {
    n = (integer*)malloc(sizeof(integer));
    *n = default_n;
    c_dim1 = *n;
    i__1 = *n;
    i__2 = *n;
    i__ = 1;
    j = 1;

    size_t c_size = ((size_t)(*n) + 1) * ((size_t)c_dim1 + 1);
    c__buf = (real*)calloc(c_size, sizeof(real));
    if (!c__buf) {
        exit(1);
    }
    c__ = c__buf - 1 - c_dim1;
}