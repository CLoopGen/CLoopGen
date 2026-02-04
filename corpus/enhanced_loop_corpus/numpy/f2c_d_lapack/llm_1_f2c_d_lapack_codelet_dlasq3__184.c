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
    for (int outer = (*i0 << 2); outer <= i__1; outer += 8) { // Increased step and introduced outer loop
        for (j4 = outer; j4 < outer + 4 && j4 <= i__1; j4 += 4) { // Inner loop handles block of 4
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
