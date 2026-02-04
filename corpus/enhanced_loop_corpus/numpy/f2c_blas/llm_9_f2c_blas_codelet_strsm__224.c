#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *m;
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
for (j = 1; j <= i__1; ++j) {
    for (i__ = *m; i__ >= 1; --i__) {
        temp = *alpha * b[i__ + j * b_dim1];
        i__2 = *m;
        // Unroll inner loop by factor of 2 to increase computational intensity
        k = i__ + 1;
        // Process two elements per iteration if possible
        while (k <= i__2 - 1) {
            temp -= a[k + i__ * a_dim1] * b[k + j * b_dim1]
                 + a[k+1 + i__ * a_dim1] * b[k+1 + j * b_dim1];
            k += 2;
        }
        // Handle remaining element if any
        if (k == i__2) {
            temp -= a[k + i__ * a_dim1] * b[k + j * b_dim1];
        }
        if (nounit) {
            temp /= a[i__ + i__ * a_dim1];
        }
        b[i__ + j * b_dim1] = temp;
    }
}
}
