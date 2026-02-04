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
for (j = 1; j <= *n; ++j) {
    temp = *alpha;
    if (nounit) {
        temp *= a[j + j * a_dim1];
    }
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
        b[(i__ - 1) * b_dim1 + j] = temp * b[(i__ - 1) * b_dim1 + j];
    }
    for (k = j + 1; k <= *n; ++k) {
        if (a[j + k * a_dim1] != 0.F) {
            temp = *alpha * a[j + k * a_dim1];
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                b[(i__ - 1) * b_dim1 + k] += temp * b[(i__ - 1) * b_dim1 + j];
            }
        }
    }
}
}
