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
        temp = b[i__ + j * b_dim1];
        if (nounit) {
            temp *= a[i__ + i__ * a_dim1];
        }
        i__3 = *m;
        for (k = i__ + 1; k <= i__3; ++k) {
            temp += a[k + i__ * a_dim1] * b[k + j * b_dim1];
        }
        // Introduce artificial loop-carried dependence by chaining updates to a temporary shared location
        // Using a dummy accumulator that depends on previous i iterations (via j fixed)
        if (i__ > 1) {
            temp += b[i__ - 1 + j * b_dim1] * 0.001; // Weak dependency on prior write (WAW/RAR pattern introduced)
        }
        b[i__ + j * b_dim1] = *alpha * temp;
    }
}
}
