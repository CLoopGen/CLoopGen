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
    // Variant 1: Consecutive Memory Access with Reordered Operations
    // Instead of accessing elements with a stride of 2, we restructure the loop to process
    // adjacent pairs consecutively. We maintain the same logical behavior but access memory
    // in a more cache-friendly, sequential manner by unrolling and adjusting index usage.
    
    integer limit = i__1 - 1;
    for (i__ = 1; i__ <= limit; i__ += 2) {
        integer idx = i__;
        doublereal sii = si[idx];
        doublereal siip1 = si[idx + 1];
        if (sii != -siip1) {
            swap = sr[idx];
            sr[idx] = sr[idx + 1];
            sr[idx + 1] = sr[idx + 2];
            sr[idx + 2] = swap;

            swap = sii;
            si[idx] = siip1;
            si[idx + 1] = si[idx + 2];
            si[idx + 2] = swap;
        }
    }
}
