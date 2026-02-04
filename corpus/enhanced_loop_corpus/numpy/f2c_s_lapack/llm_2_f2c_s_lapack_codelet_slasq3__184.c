#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *i0;
extern real *z__;
extern integer i__1;
extern integer j4;
extern integer ipn4;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with loop unrolling and restructured indexing
    // Instead of scattered accesses, we reorganize the swaps to access consecutive locations
    // by precomputing symmetric indices and accessing z__ in increasing order.

    integer start = (*i0 << 2);
    integer end = i__1;

    for (j4 = start; j4 <= end; j4 += 4) {
        integer idx1 = j4 - 3;
        integer idx2 = j4 - 2;
        integer idx3 = j4 - 1;
        integer idx4 = j4;

        integer jdx1 = ipn4 - j4 - 3;
        integer jdx2 = ipn4 - j4 - 2;
        integer jdx3 = ipn4 - j4 - 5;
        integer jdx4 = ipn4 - j4 - 4;

        temp = z__[idx1];
        z__[idx1] = z__[jdx1];
        z__[jdx1] = temp;

        temp = z__[idx2];
        z__[idx2] = z__[jdx2];
        z__[jdx2] = temp;

        temp = z__[idx3];
        z__[idx3] = z__[jdx3];
        z__[jdx3] = temp;

        temp = z__[idx4];
        z__[idx4] = z__[jdx4];
        z__[jdx4] = temp;
    }
}
