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
    // Variant 1: Consecutive memory access by unrolling and reordering accesses to improve spatial locality
    integer offset;
    for (j4 = *i0 << 2; j4 <= i__1 - 3; j4 += 4) {
        offset = ipn4 - j4;
        temp = z__[j4 - 3];
        z__[j4 - 3] = z__[offset - 3];
        z__[offset - 3] = temp;

        temp = z__[j4 - 2];
        z__[j4 - 2] = z__[offset - 2];
        z__[offset - 2] = temp;

        temp = z__[j4 - 1];
        z__[j4 - 1] = z__[offset - 5];
        z__[offset - 5] = temp;

        temp = z__[j4];
        z__[j4] = z__[offset - 4];
        z__[offset - 4] = temp;
    }
}
