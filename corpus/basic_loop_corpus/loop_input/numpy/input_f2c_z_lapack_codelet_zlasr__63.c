#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *m;
integer *n;
doublereal *c__;
doublereal *s;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
doublecomplex z__1;
doublecomplex z__2;
doublecomplex z__3;
integer i__;
integer j;
doublecomplex temp;
doublereal ctemp;
doublereal stemp;

static doublereal c_storage[1024];
static doublereal s_storage[1024];
static doublecomplex a_storage[1024 * 1024];

void init_vars() {
    const integer size_m = 512;
    const integer size_n = 1024;
    
    m = (integer*)malloc(sizeof(integer));
    n = (integer*)malloc(sizeof(integer));
    c__ = c_storage;
    s = s_storage;
    a = a_storage;
    
    *m = size_m;
    *n = size_n;
    a_dim1 = size_m;

    for (int jdx = 1; jdx <= size_m; ++jdx) {
        c__[jdx-1] = (jdx == 1) ? 1.0 : 0.8;
        s[jdx-1] = (jdx == 1) ? 0.0 : 0.6;
    }

    for (int idx = 0; idx < size_n; ++idx) {
        for (int jdx = 0; jdx < size_m; ++jdx) {
            int pos = jdx + idx * a_dim1;
            a[pos].r = (doublereal)(pos % 17);
            a[pos].i = (doublereal)(pos % 13);
        }
    }
}