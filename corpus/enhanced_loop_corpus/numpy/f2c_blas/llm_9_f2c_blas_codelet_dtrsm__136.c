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
extern integer i__3;
extern integer i__;
extern integer j;
extern integer k;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 1; k <= i__1; k += 2) {
    integer k2 = k + 1;
    if (nounit) {
        temp = 1. / a[k + k * a_dim1];
        if (k2 <= i__1) {
            doublereal temp2 = 1. / a[k2 + k2 * a_dim1];
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                b[i__ + k * b_dim1] = temp * b[i__ + k * b_dim1];
                b[i__ + k2 * b_dim1] = temp2 * b[i__ + k2 * b_dim1];
            }
        } else {
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                b[i__ + k * b_dim1] = temp * b[i__ + k * b_dim1];
            }
        }
    } else {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            if (k2 <= i__1) {
                b[i__ + k2 * b_dim1] = b[i__ + k2 * b_dim1]; 
            }
        }
    }
    for (j = k + 1; j <= *n; ++j) {
        if (a[j + k * a_dim1] != 0.) {
            temp = a[j + k * a_dim1];
            i__3 = *m;
            for (i__ = 1; i__ <= i__3; ++i__) {
                b[i__ + j * b_dim1] -= temp * b[i__ + k * b_dim1];
            }
        }
        if (k2 <= i__1 && a[j + k2 * a_dim1] != 0. && k2 <= *n) {
            temp = a[j + k2 * a_dim1];
            i__3 = *m;
            for (i__ = 1; i__ <= i__3; ++i__) {
                b[i__ + j * b_dim1] -= temp * b[i__ + k2 * b_dim1];
            }
        }
    }
    if (*alpha != 1.) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            b[i__ + k * b_dim1] *= *alpha;
            if (k2 <= i__1) {
                b[i__ + k2 * b_dim1] *= *alpha;
            }
        }
    }
}
}
