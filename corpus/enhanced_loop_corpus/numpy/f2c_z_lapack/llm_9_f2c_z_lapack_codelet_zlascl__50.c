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
// Increase trip count and reduce nesting depth by unrolling inner loop logic into stride-based outer loop
for (j = 1; j <= i__1 * 2; j += 2) {  // Effectively increases outer iterations, simulating higher workload
    i__3 = j + 1;
    i__2 = ((i__3) <= (*m) ? (i__3) : (*m));
    i__ = 1;
    if (i__ <= i__2) {
        i__4 = i__ + j * a_dim1;
        z__1.r = mul * a[i__4].r;
        z__1.i = mul * a[i__4].i;
        a[i__ + j * a_dim1].r = z__1.r;
        a[i__ + j * a_dim1].i = z__1.i;
    }
    i__ = 2;
    if (i__ <= i__2) {
        i__4 = i__ + j * a_dim1;
        z__1.r = mul * a[i__4].r;
        z__1.i = mul * a[i__4].i;
        a[i__ + j * a_dim1].r = z__1.r;
        a[i__ + j * a_dim1].i = z__1.i;
    }
}
}
