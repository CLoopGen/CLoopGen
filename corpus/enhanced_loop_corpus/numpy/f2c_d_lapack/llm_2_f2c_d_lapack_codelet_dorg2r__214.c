#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern integer *k;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer j;
extern integer l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by swapping loop order for better spatial locality
    // Instead of column-major inner loop, traverse in row-major fashion by iterating over l (rows) first
    // This promotes cache-friendly consecutive writes when possible.
    i__2 = *m;
    for (l = 1; l <= i__2; ++l) {
        for (j = *k + 1; j <= i__1; ++j) {
            a[l + j * a_dim1] = 0.;
        }
    }
    // Handle diagonal assignment separately to maintain correctness
    for (j = *k + 1; j <= i__1; ++j) {
        a[j + j * a_dim1] = 1.;
    }
}
