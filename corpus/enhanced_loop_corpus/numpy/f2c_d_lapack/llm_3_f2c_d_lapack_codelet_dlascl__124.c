#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__;
extern integer j;
extern integer k3;
extern integer k4;
extern doublereal mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic
    // Simulates non-unit stride access pattern by stepping through memory with a fixed increment
    doublereal *base = &a[1 + 1 * a_dim1]; // Starting point of access
    integer stride = a_dim1 + 1; // Diagonal-like traversal with increasing stride effect
    integer count = 0;
    integer max_elements = (k3 < k4 ? k3 : k4); // Bound based on smaller dimension

    for (j = 0; j < i__1; ++j) {
        doublereal *row_start = base + j * a_dim1;
        i__3 = k3;
        i__4 = k4 - (j + 1);
        i__2 = (i__3 < i__4 ? i__3 : i__4);
        for (i__ = 0; i__ < i__2; ++i__) {
            row_start[i__] *= mul; // Unit stride within row (consecutive)
        }
    }
}
