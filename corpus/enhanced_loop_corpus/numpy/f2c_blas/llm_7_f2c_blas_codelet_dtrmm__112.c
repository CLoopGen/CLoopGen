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
extern integer i__3;
extern integer i__;
extern integer j;
extern integer k;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    temp = 0.0;
    for (k = 1; k <= i__2; ++k) {
        doublereal bkj = b[k + j * b_dim1];
        if (bkj != 0.) {
            doublereal local_temp = *alpha * bkj;
            i__3 = k - 1;
            for (i__ = 1; i__ <= i__3; ++i__) {
                b[i__ + j * b_dim1] += local_temp * a[i__ + k * a_dim1];
            }
            if (nounit) {
                local_temp *= a[k + k * a_dim1];
            }
            b[k + j * b_dim1] = local_temp;
            temp += local_temp;
        }
    }
    if (temp == 0.0) {
        b[1 + j * b_dim1] = 1.0;
    }
}
}
