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
extern integer i__3;
extern integer i__;
extern integer j;
extern integer k;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        real temp1 = b[i__ + j * b_dim1];
        real temp2 = (j + 1 <= i__1) ? b[i__ + (j + 1) * b_dim1] : 0.0f;
        if (nounit) {
            temp1 *= a[i__ + i__ * a_dim1];
            if (j + 1 <= i__1) {
                temp2 *= a[i__ + i__ * a_dim1];
            }
        }
        i__3 = *m;
        for (k = i__ + 1; k <= i__3; ++k) {
            temp1 += a[k + i__ * a_dim1] * b[k + j * b_dim1];
            if (j + 1 <= i__1) {
                temp2 += a[k + i__ * a_dim1] * b[k + (j + 1) * b_dim1];
            }
        }
        b[i__ + j * b_dim1] = *alpha * temp1;
        if (j + 1 <= i__1) {
            b[i__ + (j + 1) * b_dim1] = *alpha * temp2;
        }
    }
}
}
