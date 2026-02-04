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
    i__1 = *n;
    for (j = k; j <= i__1; ++j) {
        temp = *alpha;
        if (nounit && k == j) {
            temp *= a[k + k * a_dim1];
        }
        if (temp != 1. || (j > k && a[j + k * a_dim1] != 0.)) {
            if (j > k) {
                temp = *alpha * a[j + k * a_dim1];
            }
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                b[i__ + j * b_dim1] = temp * b[i__ + k * b_dim1];
            }
        }
    }
}
}
