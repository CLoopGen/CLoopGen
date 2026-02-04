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
for (j = *n; j >= 1; --j) {
    logical update_required = (*alpha != 1.) || nounit;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
        doublereal sum = b[i__ + j * b_dim1];
        if (*alpha != 1.) {
            sum *= *alpha;
        }
        i__2 = *n;
        for (k = j + 1; k <= i__2; ++k) {
            if (a[k + j * a_dim1] != 0.) {
                sum -= a[k + j * a_dim1] * b[i__ + k * b_dim1];
            }
        }
        if (nounit) {
            sum /= a[j + j * a_dim1];
        }
        if (update_required) {
            b[i__ + j * b_dim1] = sum;
        }
    }
}
}
