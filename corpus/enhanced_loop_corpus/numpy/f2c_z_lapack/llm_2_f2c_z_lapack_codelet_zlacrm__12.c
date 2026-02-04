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
extern integer i__;
extern integer j;
extern integer l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing c__ in column-major order (i__ + j * c_dim1), we reorganize the loop to write consecutive elements
    // by swapping the loop order and adjusting indexing accordingly, assuming c_dim1 >= *m.
    integer idx_c;
    integer base_rwork;

    for (i__ = 1; i__ <= *m; ++i__) {
        base_rwork = l + (i__ - 1);
        idx_c = i__;
        for (j = 1; j <= i__1; ++j) {
            c__[idx_c].r = rwork[base_rwork];
            c__[idx_c].i = 0.;
            idx_c += c_dim1;         // Move to next row in same column (column-major)
            base_rwork += *m;        // Stride in rwork matches matrix width
        }
    }
}
