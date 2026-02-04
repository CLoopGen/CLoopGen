#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern integer i__1;
extern integer i0;
extern integer i4;
extern integer ipn4;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and reorganizing accesses
    // Instead of accessing strided elements (every 4th), we process two pairs of consecutive swaps
    // to improve spatial locality where possible.
    integer start = i0 << 2;
    for (i4 = start; i4 <= i__1 - 3; i4 += 4) {
        // Reorder access to group nearby indices
        integer idx1 = i4 - 3;
        integer idx2 = i4 - 1;
        integer jdx1 = ipn4 - i4 - 3;
        integer jdx2 = ipn4 - i4 - 5;

        temp = z__[idx1];
        z__[idx1] = z__[jdx1];
        z__[jdx1] = temp;

        temp = z__[idx2];
        z__[idx2] = z__[jdx2];
        z__[jdx2] = temp;
    }
}
