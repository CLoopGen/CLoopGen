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
    doublereal temp1, temp2, temp3, temp4;
    for (j4 = *i0 << 2; j4 <= i__1; j4 += 4) {
        temp1 = z__[j4 - 3];
        temp2 = z__[j4 - 2];
        temp3 = z__[j4 - 1];
        temp4 = z__[j4];
        z__[j4 - 3] = z__[ipn4 - j4 - 3];
        z__[j4 - 2] = z__[ipn4 - j4 - 2];
        z__[j4 - 1] = z__[ipn4 - j4 - 5];
        z__[j4] = z__[ipn4 - j4 - 4];
        z__[ipn4 - j4 - 3] = temp1;
        z__[ipn4 - j4 - 2] = temp2;
        z__[ipn4 - j4 - 5] = temp3;
        z__[ipn4 - j4 - 4] = temp4;
    }
}
