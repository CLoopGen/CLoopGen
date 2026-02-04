#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *m;
extern integer *n;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer k;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = *n; k >= 1; --k) {
    if (nounit) {
        temp = 1. / a[k + k * a_dim1];
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            b[i__ + k * b_dim1] = temp * b[i__ + k * b_dim1];
            i__2 = k - 1;
            for (j = 1; j <= i__2; ++j) {
                if (a[j + k * a_dim1] != 0.) {
                    b[i__ + j * b_dim1] -= a[j + k * a_dim1] * b[i__ + k * b_dim1];
                }
            }
            if (*alpha != 1.) {
                b[i__ + k * b_dim1] = *alpha * b[i__ + k * b_dim1];
            }
        }
    } else {
        i__2 = k - 1;
        for (j = 1; j <= i__2; ++j) {
            if (a[j + k * a_dim1] != 0.) {
                temp = a[j + k * a_dim1];
                i__1 = *m;
                for (i__ = 1; i__ <= i__1; ++i__) {
                    b[i__ + j * b_dim1] -= temp * b[i__ + k * b_dim1];
                }
            }
        }
        if (*alpha != 1.) {
            i__1 = *m;
            for (i__ = 1; i__ <= i__1; ++i__) {
                b[i__ + k * b_dim1] = *alpha * b[i__ + k * b_dim1];
            }
        }
    }
}
}
