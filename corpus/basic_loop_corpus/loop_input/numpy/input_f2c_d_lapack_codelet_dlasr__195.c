#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *n;
doublereal *c__;
doublereal *s;
doublereal *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
doublereal temp;
doublereal ctemp;
doublereal stemp;

static doublereal a_data[256 * 1024 * 1024 / sizeof(doublereal)] = {0.0};
static doublereal c_data[65536] = {0.0};
static doublereal s_data[65536] = {0.0};

void init_vars() {
    const integer max_j = 65535;
    const integer n_val = 1024;

    n = (integer*)malloc(sizeof(integer));
    *n = n_val;

    a_dim1 = n_val;
    i__1 = max_j;
    i__2 = *n;

    c__ = c_data;
    s = s_data;
    a = a_data;

    j = 1;
    i__ = 1;

    for (integer idx = 1; idx <= max_j; ++idx) {
        c__[idx] = 0.7071; 
        s[idx] = 0.7071;
    }

    size_t a_size = (max_j + 1) * n_val;
    if (a_size > 256 * 1024 * 1024 / sizeof(doublereal)) {
        a_size = 256 * 1024 * 1024 / sizeof(doublereal);
    }

    for (size_t i = 0; i < a_size; ++i) {
        a[i] = (doublereal)(i & 0xFF);
    }
}