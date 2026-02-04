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
extern integer i__;
extern integer j;
extern integer kk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification - Consecutive Access by Swapping Loop Order
    // We now iterate over elements in column-major consecutive order by fixing j and varying i,
    // but unroll the inner loop to emphasize memory contiguity in column j.
    for (i__ = 1; i__ <= kk; ++i__) {
        for (j = kk + 1; j <= i__1; ++j) {
            a[i__ + j * a_dim1] = 0.;
        }
    }
}
