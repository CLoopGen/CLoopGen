#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *m;
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
for (j = 1; j <= i__1; ++j) {
    temp = 0.0;
    for (k = *m; k >= 1; --k) {
        doublereal b_val = b[k + j * b_dim1];
        if (b_val != 0.) {
            doublereal alpha_b = *alpha * b_val;
            b[k + j * b_dim1] = nounit ? alpha_b * a[k + k * a_dim1] : alpha_b;
            i__2 = *m;
            for (i__ = k + 1; i__ <= i__2; ++i__) {
                b[i__ + j * b_dim1] += alpha_b * a[i__ + k * a_dim1];
            }
        }
    }
}
}
