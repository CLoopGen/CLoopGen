#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *ihi;
extern doublereal *h__;
extern doublereal *wr;
extern doublereal *wi;
extern integer h_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory layout simulation using pointer arithmetic
    // Assume column-major data in h__ is being accessed diagonally, now reindex to promote spatial locality
    // Instead of scattered diagonal access, we precompute base offsets and traverse consecutively
    doublereal *wr_base = &wr[*ihi + 1];
    doublereal *wi_base = &wi[*ihi + 1];
    doublereal *h_diag_base = &h__[(*ihi + 1) + (*ihi + 1) * h_dim1];
    integer count = i__1 - *ihi;

    for (i__ = 0; i__ < count; ++i__) {
        wr_base[i__] = h_diag_base[i__ * (h_dim1 + 1)];  // Diagonal stride in matrix
        wi_base[i__] = 0.0;
    }
    // Restore original indexing behavior by mapping i__ back if needed externally
    // Note: i__ here is used as local counter, original i__ offset is preserved via base
}
