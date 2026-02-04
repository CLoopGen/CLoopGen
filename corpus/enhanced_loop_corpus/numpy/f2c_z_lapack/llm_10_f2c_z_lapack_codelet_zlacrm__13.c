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
extern doublecomplex *c__;
extern doublereal *rwork;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern doublereal d__1;
extern doublecomplex z__1;
extern integer i__;
extern integer j;
extern integer l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 > 0 && *m > 0) {
    // Unrolled variant with reduced loop overhead and modified trip count
    integer j_end = (i__1 / 2) * 2; // Make it even for safe unrolling
    for (j = 1; j <= j_end; j += 2) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            // First j iteration
            i__3 = i__ + j * c_dim1;
            i__4 = i__ + j * c_dim1;
            d__1 = c__[i__4].r;
            i__5 = l + (j - 1) * *m + i__ - 1;
            z__1.r = d__1; z__1.i = rwork[i__5];
            c__[i__3].r = z__1.r; c__[i__3].i = z__1.i;

            // Second j iteration (unrolled)
            i__3 = i__ + (j+1) * c_dim1;
            i__4 = i__ + (j+1) * c_dim1;
            d__1 = c__[i__4].r;
            i__5 = l + j * *m + i__ - 1;
            z__1.r = d__1; z__1.i = rwork[i__5];
            c__[i__3].r = z__1.r; c__[i__3].i = z__1.i;
        }
    }
    // Handle remaining j if i__1 is odd
    for (; j <= i__1; ++j) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__ + j * c_dim1;
            i__4 = i__ + j * c_dim1;
            d__1 = c__[i__4].r;
            i__5 = l + (j - 1) * *m + i__ - 1;
            z__1.r = d__1; z__1.i = rwork[i__5];
            c__[i__3].r = z__1.r; c__[i__3].i = z__1.i;
        }
    }
}
}
