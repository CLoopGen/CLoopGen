#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer n_data = 2048;
integer *n = &n_data;

integer ihi_data = 1536;
integer *ihi = &ihi_data;

doublereal *a;
integer a_dim1;

integer i__1 = 1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    const integer size = 2048;
    a_dim1 = size;
    
    n_data = size;
    ihi_data = (integer)(0.75 * size);
    i__1 = 1;

    a = (doublereal*)calloc(size * size, sizeof(doublereal));
    if (!a) {
        exit(1);
    }
}