#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sr;
extern real *si;
extern integer i__1;
extern integer i__;
extern real swap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 4 instead of 2, processing every other pair
    // This changes the access pattern to a strided one, potentially useful in cache blocking or prefetching scenarios
    // We adjust loop bounds to ensure i__+2 remains valid
    integer step = 4;
    integer max = i__1 - 2; // To prevent out-of-bounds access at i__+2

    for (i__ = 1; i__ <= max; i__ += step) {
        // Access pattern now skips adjacent pairs, creating a strided traversal
        if (si[i__] != -si[i__ + 1]) {
            swap = sr[i__];
            sr[i__]       = sr[i__ + 1];
            sr[i__ + 1]   = sr[i__ + 2];
            sr[i__ + 2]   = swap;

            swap = si[i__];
            si[i__]       = si[i__ + 1];
            si[i__ + 1]   = si[i__ + 2];
            si[i__ + 2]   = swap;
        }

        // Optional: process the skipped pair conditionally if within bounds
        integer next_i = i__ + 2;
        if (next_i <= max && si[next_i] != -si[next_i + 1]) {
            swap = sr[next_i];
            sr[next_i]       = sr[next_i + 1];
            sr[next_i + 1]   = sr[next_i + 2];
            sr[next_i + 2]   = swap;

            swap = si[next_i];
            si[next_i]       = si[next_i + 1];
            si[next_i + 1]   = si[next_i + 2];
            si[next_i + 2]   = swap;
        }
    }
}
