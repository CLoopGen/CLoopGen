#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer m_val = 500;
integer n_val = 500;
doublereal alpha_val = 1.5;
logical nounit_val = 1;

integer a_dim1_val = 500;
integer b_dim1_val = 500;

doublereal *a_data;
doublereal *b_data;

integer *m = &m_val;
integer *n = &n_val;
doublereal *alpha = &alpha_val;
doublereal *a = NULL;
doublereal *b = NULL;
integer a_dim1 = 500;
integer b_dim1 = 500;
integer i__1 = 500;
integer i__2;
integer i__3;
integer i__;
integer j;
integer k;
doublereal temp;
logical nounit = 1;

void init_vars() {
    a_data = (doublereal*)calloc(a_dim1 * n_val, sizeof(doublereal));
    b_data = (doublereal*)calloc(b_dim1 * n_val, sizeof(doublereal));

    a = a_data;
    b = b_data;

    for (integer idx = 0; idx < a_dim1 * n_val; ++idx) {
        a_data[idx] = sin(idx * 0.01);
    }
    for (integer idx = 0; idx < b_dim1 * n_val; ++idx) {
        b_data[idx] = cos(idx * 0.01);
    }

    i__1 = n_val;
}