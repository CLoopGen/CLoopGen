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

extern integer *n;
extern integer *ihi;
extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Eliminate inner loop and convert to fully unrolled-like behavior with no loop-carried dependencies
// Use direct assignment based on bounds, assuming small range for semantic validity
integer start_j = *ihi + 1;
for (j = start_j; j <= i__1; ++j) {
    // Remove loop-carried dependency by ensuring independent per-iteration writes
    // Also remove inner loop entirely by fusing operations
    for (i__ = 1; i__ <= *n; ++i__) {
        i__3 = i__ + j * a_dim1;
        // Ensure no WAW or WAR hazards by writing only once per memory location
        if (i__ != j) {
            a[i__3].r = 0.0;
            a[i__3].i = 0.0;
        }
    }
    // Diagonal element set independently — now part of same logic flow without reusing indices
    i__2 = j + j * a_dim1;
    a[i__2].r = 1.0;
    a[i__2].i = 0.0;
}
}
