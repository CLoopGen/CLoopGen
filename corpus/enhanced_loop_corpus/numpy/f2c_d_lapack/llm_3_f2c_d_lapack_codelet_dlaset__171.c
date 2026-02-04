#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *beta;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access Pattern via Row-major Emulation
    // Flatten the diagonal access into a loop that writes to memory locations in a more consecutive pattern
    // by reorganizing how indices are computed, though still targeting diagonal elements
    // We simulate consecutive writes by precomputing the next address increment
    integer offset = 0;
    for (i__ = 1; i__ <= i__1; ++i__) {
        a[offset + i__] = *beta;  // Now accesses are based on increasing offset per row
        offset += a_dim1;
    }
}
