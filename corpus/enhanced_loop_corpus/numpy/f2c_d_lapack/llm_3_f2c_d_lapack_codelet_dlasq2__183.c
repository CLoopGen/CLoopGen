#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern integer i__1;
extern integer i0;
extern integer i4;
extern integer ipn4;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Indirect Access via Offset Array
    // Introduce a fixed offset array to simulate indirect but predictable access.
    // This models scenarios where memory patterns are not linear but follow a known stride schedule.
    const integer offsets[4] = { -3, -1, -5, -3 };  // Original index adjustments
    integer idx1, idx2;
    for (i4 = i0 << 2; i4 <= i__1; i4 += 4) {
        idx1 = i4 + offsets[0];
        idx2 = ipn4 - i4 + offsets[2];  // Note: -i4 -3 => ipn4 - i4 -3 = ipn4 - (i4 + 3)
        temp = z__[idx1];
        z__[idx1] = z__[idx2];
        z__[idx2] = temp;

        idx1 = i4 + offsets[1];
        idx2 = ipn4 - i4 + offsets[3];  // -i4 -5 = ipn4 - (i4 + 5)
        temp = z__[idx1];
        z__[idx1] = z__[idx2];
        z__[idx2] = temp;
    }
}
