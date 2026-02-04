#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal beta_val = 3.14159;
doublereal *beta = &beta_val;

integer a_dim1 = 1024;
integer i__1 = 1024;
integer i__ = 0;

doublereal *a = NULL;

void init_vars() {
    size_t size = (size_t)(a_dim1 + 1) * (i__1 + 1);
    a = (doublereal *)calloc(size, sizeof(doublereal));
    if (!a) {
        exit(1);
    }
}