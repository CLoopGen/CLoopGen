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
extern integer *k;
extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer j;
extern integer l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    // Introduce loop-carried dependence by making inner loop depend on previous j iteration
    if (j > 1) {
        i__3 = (j - 1) + j * a_dim1;
        a[i__3].r += a[i__3 - a_dim1].r;
        a[i__3].i += a[i__3 - a_dim1].i;
    }
    for (l = *k + 1; l <= i__2; ++l) {
        i__3 = l + j * a_dim1;
        // Add artificial dependence: current write depends on prior row same column
        if (l > *k + 1) {
            a[i__3].r = a[l - 1 + j * a_dim1].r + 0.;
            a[i__3].i = a[l - 1 + j * a_dim1].i + 0.;
        } else {
            a[i__3].r = 0., a[i__3].i = 0.;
        }
    }
    if (j > *k && j <= *m) {
        i__2 = j + j * a_dim1;
        // Maintain WAW possibility: write after potential prior update in loop
        a[i__2].r = 1. , a[i__2].i = 0.;
    }
}
}
