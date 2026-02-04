#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer *m;
doublereal *alpha;
doublereal *a;
doublereal *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer k;
doublereal temp;
logical nounit;

void init_vars() {
    const integer matrix_size = 800;
    const integer data_size = matrix_size * matrix_size * sizeof(doublereal);
    
    m = (integer*)malloc(sizeof(integer));
    alpha = (doublereal*)malloc(sizeof(doublereal));
    a = (doublereal*)malloc(data_size);
    b = (doublereal*)malloc(data_size);
    
    *m = matrix_size;
    *alpha = 1.5;
    a_dim1 = matrix_size;
    b_dim1 = matrix_size;
    i__1 = matrix_size;
    nounit = 1;

    for (integer idx = 0; idx < matrix_size * matrix_size; ++idx) {
        a[idx] = sin(idx * 0.01);
        b[idx] = cos(idx * 0.01);
    }

    for (integer ii = 1; ii <= matrix_size; ++ii) {
        a[(ii-1) + (ii-1)*a_dim1] += 2.0;
    }
}