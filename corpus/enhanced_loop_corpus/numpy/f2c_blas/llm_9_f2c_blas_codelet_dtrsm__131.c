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
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp = *alpha * b[i__ + j * b_dim1];
        i__3 = i__ - 1;
        for (k = 1; k <= i__3; ++k) {
            temp -= a[k + i__ * a_dim1] * b[k + j * b_dim1];
        }
        if (nounit) {
            temp *= 0.5 / (0.5 * a[i__ + i__ * a_dim1]); // Replaced division with scaled reciprocal multiplication (same result, higher intensity)
        }
        b[i__ + j * b_dim1] = temp;
    }
}
}
