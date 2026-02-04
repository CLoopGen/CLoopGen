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
    // Variant 2: Strided memory access with stride of 8, processing two pairs per iteration
    // Simulates a strided traversal by doubling the step and accessing non-adjacent elements.
    // This changes access pattern from dense to strided, potentially improving cache behavior
    // in some contexts or enabling vectorization.

    integer start = (*i0 << 2);
    integer end = i__1;

    for (j4 = start; j4 <= end; j4 += 8) {  // Increased step to create strided pattern

        // First group (original j4)
        temp = z__[j4 - 3];
        z__[j4 - 3] = z__[ipn4 - j4 - 3];
        z__[ipn4 - j4 - 3] = temp;

        temp = z__[j4 - 2];
        z__[j4 - 2] = z__[ipn4 - j4 - 2];
        z__[ipn4 - j4 - 2] = temp;

        temp = z__[j4 - 1];
        z__[j4 - 1] = z__[ipn4 - j4 - 5];
        z__[ipn4 - j4 - 5] = temp;

        temp = z__[j4];
        z__[j4] = z__[ipn4 - j4 - 4];
        z__[ipn4 - j4 - 4] = temp;

        // Second group (j4 + 4), if within bounds
        integer j5 = j4 + 4;
        if (j5 <= end) {
            temp = z__[j5 - 3];
            z__[j5 - 3] = z__[ipn4 - j5 - 3];
            z__[ipn4 - j5 - 3] = temp;

            temp = z__[j5 - 2];
            z__[j5 - 2] = z__[ipn4 - j5 - 2];
            z__[ipn4 - j5 - 2] = temp;

            temp = z__[j5 - 1];
            z__[j5 - 1] = z__[ipn4 - j5 - 5];
            z__[ipn4 - j5 - 5] = temp;

            temp = z__[j5];
            z__[j5] = z__[ipn4 - j5 - 4];
            z__[ipn4 - j5 - 4] = temp;
        }
    }
}
