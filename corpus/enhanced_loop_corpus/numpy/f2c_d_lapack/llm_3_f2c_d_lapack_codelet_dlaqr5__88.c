#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *sr;
extern doublereal *si;
extern integer i__1;
extern integer i__;
extern doublereal swap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Increased Stride
    // Modify access pattern to use a larger stride (e.g., every 4th element)
    // This changes spatial locality and simulates processing non-adjacent segments.
    // The logic is preserved within the new access pattern, though only applicable
    // where indices remain in bounds. Adjust loop bound accordingly.

    integer stride = 4;
    integer adjusted_bound = (i__1 - 2) / stride * stride + 1; // Ensure i__ + 2 stays in range
    for (i__ = 1; i__ <= adjusted_bound; i__ += stride) {
        integer base = i__;
        if (si[base] != -si[base + 1]) {
            swap = sr[base];
            sr[base] = sr[base + 1];
            sr[base + 1] = sr[base + 2];
            sr[base + 2] = swap;

            swap = si[base];
            si[base] = si[base + 1];
            si[base + 1] = si[base + 2];
            si[base + 2] = swap;
        }
    }
}
