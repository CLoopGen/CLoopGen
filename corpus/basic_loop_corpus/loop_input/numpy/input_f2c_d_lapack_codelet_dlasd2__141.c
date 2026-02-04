#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *vt;
doublereal *vt2;
integer vt_dim1;
integer vt2_dim1;
integer i__1;
doublereal c__;
integer i__;
integer m;
doublereal s;
integer nlp2;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of total data (adjustable)
    vt_dim1 = 1024;
    vt2_dim1 = 1024;
    m = 100;
    s = 0.75;
    c__ = 0.25;
    nlp2 = 1;
    i__1 = 100000;

    size_t vt_len = (m + i__1 * vt_dim1) + 1;
    size_t vt2_len = (i__1 * vt2_dim1) + 1024;

    vt = (doublereal*)calloc(vt_len, sizeof(doublereal));
    vt2 = (doublereal*)calloc(vt2_len, sizeof(doublereal));

    if (!vt || !vt2) {
        exit(1);
    }

    for (size_t i = 0; i < vt_len; ++i) {
        vt[i] = 1.0;
    }
    for (size_t i = 0; i < vt2_len; ++i) {
        vt2[i] = 0.0;
    }
}