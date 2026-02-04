#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *m;
extern integer *n;
extern real *alpha;
extern real *a;
extern real *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer k;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = *n; k >= 1; --k) {
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
        real b_ik = b[i__ + k * b_dim1];
        if (nounit) {
            b_ik = (1.F / a[k + k * a_dim1]) * b_ik;
        }
        if (*alpha != 1.F) {
            b_ik = *alpha * b_ik;
        }
        b[i__ + k * b_dim1] = b_ik;
    }
    i__1 = k - 1;
    for (j = 1; j <= i__1; ++j) {
        real a_jk = a[j + k * a_dim1];
        if (a_jk != 0.F) {
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                real update = a_jk * b[i__ + k * b_dim1];
                b[i__ + j * b_dim1] = b[i__ + j * b_dim1] - update;
            }
        }
    }
}
}
