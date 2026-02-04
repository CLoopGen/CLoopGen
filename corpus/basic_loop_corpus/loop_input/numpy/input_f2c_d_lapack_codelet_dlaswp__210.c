#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef double doublereal;
typedef int integer;

doublereal *a;
integer *ipiv;
integer *incx;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;
integer k;
integer i1;
integer i2;
integer ip;
integer ix;
integer ix0;
integer inc;
doublereal temp;

void init_vars() {
    const integer n = 2048;  
    const integer m = 2048;  

    a_dim1 = m;
    i__1 = n;
    i1 = 1;
    i2 = n;
    i__3 = 1;
    inc = 1;
    ix0 = 1;
    *incx = 1;

    a = (doublereal*)calloc((size_t)(m * (n + 1)), sizeof(doublereal));
    if (!a) exit(1);

    ipiv = (integer*)malloc((size_t)(n + 32) * sizeof(integer));
    if (!ipiv) exit(1);

    for (integer idx = 0; idx <= n; ++idx) {
        ipiv[idx] = rand() % m + 1;
        if (ipiv[idx] == idx) {
            ipiv[idx] = (ipiv[idx] + 1) % m + 1;
        }
    }

    for (integer row = 1; row <= m; ++row) {
        for (integer col = 1; col <= n; ++col) {
            a[row + col * a_dim1] = (doublereal)(rand()) / RAND_MAX;
        }
    }
}

static integer static_incx = 1;
static integer* init_pointers() {
    incx = &static_incx;
    return incx;
}

static void init_common() {
    init_pointers();
    init_vars();
}

__attribute__((constructor))
static void auto_init() {
    init_common();
}