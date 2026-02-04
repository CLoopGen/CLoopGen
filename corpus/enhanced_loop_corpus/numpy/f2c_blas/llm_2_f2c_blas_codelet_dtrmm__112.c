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
    for (k = 1; k <= i__2; ++k) {
        if (b[(j-1) * b_dim1 + k] != 0.) {
            temp = *alpha * b[(j-1) * b_dim1 + k];
            i__3 = k - 1;
            for (i__ = 1; i__ <= i__3; ++i__) {
                b[(j-1) * b_dim1 + i__] += temp * a[(k-1) * a_dim1 + i__];
            }
            if (nounit) {
                temp *= a[(k-1) * a_dim1 + k];
            }
            b[(j-1) * b_dim1 + k] = temp;
        }
    }
}
}
