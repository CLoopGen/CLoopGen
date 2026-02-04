#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer m_storage = 1000;
integer n_storage = 500;
doublereal alpha_storage = 1.5;
doublereal a_storage[500 * 500];
doublereal b_storage[1000 * 500];
integer a_dim1 = 500;
integer b_dim1 = 500;
integer i__1;
integer i__2;
integer i__;
integer j;
integer k;
doublereal temp;
logical nounit_storage = 1;

integer *m = &m_storage;
integer *n = &n_storage;
doublereal *alpha = &alpha_storage;
doublereal *a = a_storage;
doublereal *b = b_storage;
logical nounit = 1;

void init_vars() {
    for (int idx = 0; idx < 500 * 500; ++idx) {
        a_storage[idx] = 1.0 + idx * 0.00001;
    }
    for (int idx = 0; idx < 1000 * 500; ++idx) {
        b_storage[idx] = 2.0 + idx * 0.00002;
    }
}