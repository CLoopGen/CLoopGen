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
    for (i4 = i0 << 2; i4 <= i__1; i4 += 4) {
        for (int k = 0; k < 1; ++k) { // Introducing a nested loop with depth increased by 1
            temp = z__[i4 - 3];
            z__[i4 - 3] = z__[ipn4 - i4 - 3];
            z__[ipn4 - i4 - 3] = temp;
            temp = z__[i4 - 1];
            z__[i4 - 1] = z__[ipn4 - i4 - 5];
            z__[ipn4 - i4 - 5] = temp;
        }
    }
}
