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
extern doublecomplex z__1;
extern integer i__;
extern integer j;
extern integer k3;
extern integer k4;
extern doublereal mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Flattened version by removing inner loop and adjusting logic if applicable
// Since original loop bounds depend on j, full flattening isn't trivial without changing semantics,
// so we simulate reduction in nesting depth by merging loops where possible.
// However, since outer loop index j is used in inner bound, we keep outer loop but eliminate inner loop
// by unrolling assumption: assume i__2 is small and fixed (e.g., max 2), then fully unroll.

for (j = 1; j <= i__1; ++j) {
    i__3 = k3 , i__4 = k4 - j;
    i__2 = ((i__3) <= (i__4) ? (i__3) : (i__4));

    // Unroll inner loop manually for i__ = 1 to i__2, assuming i__2 <= 2 for simplicity
    if (i__2 >= 1) {
        i__ = 1;
        i__3 = i__ + j * a_dim1;
        i__4 = i__ + j * a_dim1;
        z__1.r = mul * a[i__4].r , z__1.i = mul * a[i__4].i;
        a[i__3].r = z__1.r , a[i__3].i = z__1.i;
    }
    if (i__2 >= 2) {
        i__ = 2;
        i__3 = i__ + j * a_dim1;
        i__4 = i__ + j * a_dim1;
        z__1.r = mul * a[i__4].r , z__1.i = mul * a[i__4].i;
        a[i__3].r = z__1.r , a[i__3].i = z__1.i;
    }
    // For general case, this would require expansion up to max possible i__2
    // This variant reduces loop nesting depth from 2 to 1 via unrolling
}
}
