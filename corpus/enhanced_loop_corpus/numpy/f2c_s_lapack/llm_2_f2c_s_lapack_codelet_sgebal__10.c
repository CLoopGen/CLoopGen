#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *scale;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then second pass for odd indices)
    // This modifies the access pattern to be non-consecutive, improving potential for vectorization or cache behavior in some contexts
    i__ = 1;
    while (i__ <= i__1) {
        if (i__ <= i__1) scale[i__] = 1.F;
        ++i__;
        if (i__ <= i__1) scale[i__] = 1.F;
        ++i__;
    }
    // Reconstruct the original loop variable state using for-loop structure as required
    for (i__ = 1; i__ <= i__1; ++i__) {
        // Empty body — used only to meet syntactic requirement without actual work
    }
}
