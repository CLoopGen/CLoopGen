#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern doublecomplex z__1;
extern integer i__;
extern integer j;
extern integer k1;
extern integer k2;
extern integer k3;
extern integer k4;
extern doublereal mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__3 = k1 - j;
    i__4 = k3 , i__5 = k4 - j;
    i__2 = ((i__4) <= (i__5) ? (i__4) : (i__5));
    doublecomplex temp_r = {0.0, 0.0};  // Local accumulation to remove immediate WAW
    for (i__ = ((i__3) >= (k2) ? (i__3) : (k2)); i__ <= i__2; ++i__) {
        i__4 = i__ + j * a_dim1;
        // Remove loop-carried dependency by using temporary
        temp_r.r += mul * a[i__4].r;
        temp_r.i += mul * a[i__4].i;
    }
    // Apply accumulated result outside inner loop to break per-iteration write dependencies
    for (i__ = ((i__3) >= (k2) ? (i__3) : (k2)); i__ <= i__2; ++i__) {
        i__3 = i__ + j * a_dim1;
        a[i__3].r = temp_r.r;
        a[i__3].i = temp_r.i;
    }
}
}
