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
    for (i4 = i0 << 2; i4 <= i__1; i4 += 4) {
        temp = z__[i4 - 3];
        z__[i4 - 3] = z__[ipn4 - i4 - 3];
        z__[ipn4 - i4 - 3] = temp;
        // Introduce artificial loop-carried dependency via temp reuse
        temp = z__[ipn4 - i4 - 3] + z__[i4 - 3]; // WAW and RAW on previous writes
        temp = z__[i4 - 1];
        z__[i4 - 1] = z__[ipn4 - i4 - 5];
        z__[ipn4 - i4 - 5] = temp;
    }
}
