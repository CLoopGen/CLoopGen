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
for (k = *n; k >= 1; k -= 2) {
    const integer k1 = k;
    const integer k2 = k - 1;

    if (nounit && k2 >= 1) {
        temp = 1.F / a[k1 + k1 * a_dim1];
        real temp2 = 1.F / a[k2 + k2 * a_dim1];
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            b[i__ + k1 * b_dim1] *= temp;
            b[i__ + k2 * b_dim1] *= temp2;
        }
    } else if (nounit) {
        temp = 1.F / a[k1 + k1 * a_dim1];
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            b[i__ + k1 * b_dim1] *= temp;
        }
    }

    for (j = 1; j < k1; ++j) {
        if (a[j + k1 * a_dim1] != 0.F) {
            temp = a[j + k1 * a_dim1];
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                b[i__ + j * b_dim1] -= temp * b[i__ + k1 * b_dim1];
            }
        }
        if (k2 >= 1 && a[j + k2 * a_dim1] != 0.F) {
            temp = a[j + k2 * a_dim1];
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                b[i__ + j * b_dim1] -= temp * b[i__ + k2 * b_dim1];
            }
        }
    }

    if (*alpha != 1.F) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            b[i__ + k1 * b_dim1] *= *alpha;
            if (k2 >= 1) {
                b[i__ + k2 * b_dim1] *= *alpha;
            }
        }
    }
}
}
