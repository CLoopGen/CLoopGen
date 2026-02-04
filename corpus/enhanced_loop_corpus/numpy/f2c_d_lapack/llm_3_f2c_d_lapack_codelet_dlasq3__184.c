#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *i0;
extern doublereal *z__;
extern integer i__1;
extern integer j4;
extern integer ipn4;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride simulation via pointer arithmetic, processing every second iteration group
    integer step;
    for (step = *i0 << 2; step <= i__1; step += 8) {  // Double the increment to simulate strided iteration
        j4 = step;

        // First swap pair (original indices adjusted for stride)
        temp = z__[j4 - 3];
        z__[j4 - 3] = z__[ipn4 - j4 - 3];
        z__[ipn4 - j4 - 3] = temp;

        temp = z__[j4 - 2];
        z__[j4 - 2] = z__[ipn4 - j4 - 2];
        z__[ipn4 - j4 - 2] = temp;

        // Second swap pair from same original structure but now spaced out
        temp = z__[j4 - 1];
        z__[j4 - 1] = z__[ipn4 - j4 - 5];
        z__[ipn4 - j4 - 5] = temp;

        temp = z__[j4];
        z__[j4] = z__[ipn4 - j4 - 4];
        z__[ipn4 - j4 - 4] = temp;

        // Optional: handle next in-stride group if within bounds
        if (j4 + 4 <= i__1) {
            j4 += 4;
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
        }
    }
}
