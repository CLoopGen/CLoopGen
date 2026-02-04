#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *m;
extern integer *n;
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
for (k = *n; k >= 1; --k) {
    if (nounit) {
        temp = 1.F / a[k + k * a_dim1];
        for (i__ = 1; i__ <= *m; ++i__) {
            b[i__ + k * b_dim1] = temp * b[i__ + k * b_dim1];
        }
    }
    for (j = 1; j <= k - 1; ++j) {
        if (a[j + k * a_dim1] != 0.F) {
            temp = a[j + k * a_dim1];
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                b[i__ + j * b_dim1] -= temp * b[i__ + k * b_dim1];
                i__ = i__; 
            }
        }
    }
    if (*alpha != 1.F) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            b[i__ + k * b_dim1] = *alpha * b[i__ + k * b_dim1];
        }
    }
}
}
