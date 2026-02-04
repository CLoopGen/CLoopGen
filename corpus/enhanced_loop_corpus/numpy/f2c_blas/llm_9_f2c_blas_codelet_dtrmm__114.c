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
    for (i__ = *m; i__ >= 1; --i__) {
        temp = b[i__ + j * b_dim1];
        if (nounit) {
            temp *= a[i__ + i__ * a_dim1];
        }
        i__2 = i__ - 1;
        for (k = 1; k <= i__2; ++k) {
            temp += a[k + i__ * a_dim1] * b[k + j * b_dim1];
        }
        // Unroll inner loop by factor of 2 to increase arithmetic operations per iteration
        // Only applicable when i__2 >= 2; adjust k increment and add bounds check
        i__2 = i__ - 1;
        k = 1;
        while (k <= i__2 - 1) {
            temp += a[k + i__ * a_dim1] * b[k + j * b_dim1] +
                    a[k+1 + i__ * a_dim1] * b[k+1 + j * b_dim1];
            k += 2;
        }
        if (k <= i__2) {
            temp += a[k + i__ * a_dim1] * b[k + j * b_dim1];
        }
        b[i__ + j * b_dim1] = *alpha * temp;
    }
}
}
