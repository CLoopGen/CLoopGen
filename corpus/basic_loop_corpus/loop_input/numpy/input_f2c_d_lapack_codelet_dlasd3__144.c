#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *vt2;
integer vt2_dim1;
integer i__1;
integer i__;
integer nlp2;
integer ktemp;

void init_vars() {
    const size_t data_size = 134217728; // 128 MB of data (adjustable)
    vt2_dim1 = 8192;
    nlp2 = 1;
    i__1 = data_size / sizeof(doublereal) / vt2_dim1 - 1;
    ktemp = vt2_dim1;

    if (i__1 < nlp2) i__1 = nlp2;

    vt2 = (doublereal*)aligned_alloc(64, (i__1 * vt2_dim1 + ktemp + 1) * sizeof(doublereal));
    for (size_t i = 0; i < (size_t)(i__1 * vt2_dim1 + ktemp + 1); ++i) {
        vt2[i] = (doublereal)(i & 511);
    }
}