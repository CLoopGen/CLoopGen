#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *k;
doublereal *q;
doublereal *s;
integer q_dim1;
integer s_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    i__1 = 5000;   // outer loop bound
    k = (integer*)malloc(sizeof(integer));
    *k = 5000;     // inner loop bound

    q_dim1 = 5000;
    s_dim1 = 5000;

    size_t q_size = (size_t)(q_dim1 + 1) * (i__1 + 1);
    size_t s_size = (size_t)(s_dim1 + 1) * (i__1 + 1);

    q = (doublereal*)calloc(q_size, sizeof(doublereal));
    s = (doublereal*)calloc(s_size, sizeof(doublereal));
}