#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal beta_val = 1.5;
doublereal *beta = &beta_val;

integer c_dim1 = 2048;
integer i__1 = 2048;
integer i__2;
integer i__;
integer j;

doublereal *c__;

void init_vars() {
    size_t total_size = (size_t)(c_dim1 + 1) * (size_t)(i__1 + 1);
    c__ = (doublereal *)calloc(total_size, sizeof(doublereal));
    if (c__ == NULL) {
        exit(1);
    }
}