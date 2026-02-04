#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern integer *ihi;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Modify memory access pattern to use strided access with step size of 2, unrolling the inner loops
    // This variant accesses array elements in a non-consecutive (strided) manner for better cache behavior in some architectures
    for (j = *ihi; j >= i__1; --j) {
        i__2 = j - 1;
        // Unroll by 2 and access with stride 2 (even indices first, then odd)
        for (i__ = 1; i__ <= i__2; i__ += 2) {
            if (i__ <= i__2) {
                a[i__ + j * a_dim1] = 0.;
            }
            if (i__ + 1 <= i__2) {
                a[i__ + 1 + j * a_dim1] = 0.;
            }
        }
        i__2 = *ihi;
        for (i__ = j + 1; i__ <= i__2; i__ += 2) {
            if (i__ <= i__2) {
                a[i__ + j * a_dim1] = a[i__ + (j - 1) * a_dim1];
            }
            if (i__ + 1 <= i__2) {
                a[i__ + 1 + j * a_dim1] = a[i__ + 1 + (j - 1) * a_dim1];
            }
        }
        i__2 = *n;
        for (i__ = *ihi + 1; i__ <= i__2; i__ += 2) {
            if (i__ <= i__2) {
                a[i__ + j * a_dim1] = 0.;
            }
            if (i__ + 1 <= i__2) {
                a[i__ + 1 + j * a_dim1] = 0.;
            }
        }
    }
}
