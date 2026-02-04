#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef int logical;

extern real *a;
extern real *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    if (x[j] != 0.F) {
        temp = x[j];
        i__2 = j - 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            x[i__] += temp * a[i__ + j * a_dim1];
        }
        if (nounit) {
            x[j] *= a[j + j * a_dim1];
        }
    }
    if (j + 1 <= i__1 && x[j + 1] != 0.F) {
        temp = x[j + 1];
        i__2 = j;
        for (i__ = 1; i__ <= i__2; ++i__) {
            x[i__] += temp * a[i__ + (j + 1) * a_dim1];
        }
        if (nounit) {
            x[j + 1] *= a[(j + 1) + (j + 1) * a_dim1];
        }
    }
}
}
