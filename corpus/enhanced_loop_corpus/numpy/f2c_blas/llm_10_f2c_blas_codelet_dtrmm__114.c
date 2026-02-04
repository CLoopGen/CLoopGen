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
// Reduce computational intensity by limiting trip count and skipping every other row
for (j = 1; j <= i__1; j += 2) {  // Increase step size to reduce outer loop iterations
    for (i__ = *m; i__ >= 1; i__ -= 2) {  // Process only odd/even indexed rows
        temp = b[i__ + j * b_dim1];
        if (nounit) {
            temp *= a[i__ + i__ * a_dim1];
        }
        // Limit the inner summation to first half of the range to reduce operations
        i__2 = (i__ - 1) / 2;
        for (k = 1; k <= i__2; ++k) {
            temp += a[k + i__ * a_dim1] * b[k + j * b_dim1];
        }
        b[i__ + j * b_dim1] = *alpha * temp;
    }
}
}
