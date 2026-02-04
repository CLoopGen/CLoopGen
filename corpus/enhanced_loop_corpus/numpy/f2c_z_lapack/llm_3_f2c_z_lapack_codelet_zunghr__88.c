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
extern integer i__4;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant 2: Strided memory access using fixed stride and linear index traversal
// Reformulate nested loops to iterate over row indices with explicit stride
// Access pattern becomes more regular and potentially vectorizable

integer col_stride = a_dim1;
for (j = *ihi; j >= i__1; --j) {
    integer base_idx_j = j * col_stride;      // Starting index for column j
    integer base_idx_jm1 = (j - 1) * col_stride; // Starting index for column j-1

    // Zero upper part: rows 1 to j-1 in column j
    for (i__ = 1; i__ <= j - 1; ++i__) {
        integer idx = i__ + base_idx_j;
        a[idx].r = 0.0;
        a[idx].i = 0.0;
    }

    // Copy middle segment: rows j+1 to ihi from column j-1 to j
    for (i__ = j + 1; i__ <= *ihi; ++i__) {
        integer dst_idx = i__ + base_idx_j;
        integer src_idx = i__ + base_idx_jm1;
        a[dst_idx].r = a[src_idx].r;
        a[dst_idx].i = a[src_idx].i;
    }

    // Zero lower part: rows ihi+1 to n in column j
    for (i__ = *ihi + 1; i__ <= *n; ++i__) {
        integer idx = i__ + base_idx_j;
        a[idx].r = 0.0;
        a[idx].i = 0.0;
    }
}
}
