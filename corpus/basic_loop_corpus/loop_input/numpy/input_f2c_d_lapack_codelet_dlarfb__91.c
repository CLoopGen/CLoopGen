#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *k;
doublereal *c__;
doublereal *work;
integer c_dim1;
integer work_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer lastc;
integer lastv;

void init_vars() {
    const integer size_c = 8192;
    const integer size_work = 8192;
    
    k = (integer*)malloc(sizeof(integer));
    *k = 1;

    lastv = 64;
    lastc = 64;
    i__1 = 64;

    c_dim1 = 128;
    work_dim1 = 128;

    c__ = (doublereal*)calloc(size_c, sizeof(doublereal));
    work = (doublereal*)calloc(size_work, sizeof(doublereal));

    for (integer idx = 0; idx < size_work; ++idx) {
        work[idx] = (doublereal)(idx % 100) / 10.0;
    }

    for (integer idx = 0; idx < size_c; ++idx) {
        c__[idx] = (doublereal)(idx % 200) / 5.0;
    }
}