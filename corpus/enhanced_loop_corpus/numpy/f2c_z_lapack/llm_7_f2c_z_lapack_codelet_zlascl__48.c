#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

extern integer *m;
extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern doublecomplex z__1;
extern integer i__;
extern integer j;
extern doublereal mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    // Introduce temporary accumulation to remove immediate write-write (WAW) and write-read (WAR) dependencies
    doublecomplex temp_sum;
    temp_sum.r = 0.0;
    temp_sum.i = 0.0;
    for (i__ = j; i__ <= i__2; ++i__) {
        i__4 = i__ + j * a_dim1;
        // Accumulate scaled values in a local temporary (reduction-like pattern)
        temp_sum.r += mul * a[i__4].r;
        temp_sum.i += mul * a[i__4].i;
    }
    // Apply the accumulated result once per outer loop iteration (removes inner loop WAW)
    for (i__ = j; i__ <= i__2; ++i__) {
        i__3 = i__ + j * a_dim1;
        a[i__3].r = temp_sum.r;
        a[i__3].i = temp_sum.i;
    }
}
}
