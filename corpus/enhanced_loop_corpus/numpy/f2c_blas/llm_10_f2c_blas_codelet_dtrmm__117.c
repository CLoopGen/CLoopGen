#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *m;
extern integer *n;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer k;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1 && j <= 100; ++j) { // Bound the outer loop to cap computational load
    temp = *alpha;
    if (nounit) {
        temp *= a[j + j * a_dim1];
    }
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        b[i__ + j * b_dim1] *= temp; // Replaced assignment with fused multiply (simpler operation pattern)
    }
    // Eliminated the inner dependency loop entirely to reduce arithmetic intensity
    // This creates a more compute-light variant focused on simple scaling
}
}
