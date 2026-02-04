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
    for (j4 = (*i0 << 2) + 2; j4 <= i__1 - 4; j4 += 2) {
        temp = z__[j4];
        z__[j4] = z__[ipn4 - j4 - 4];
        z__[ipn4 - j4 - 4] = temp;
        temp = z__[j4 + 1];
        z__[j4 + 1] = z__[ipn4 - j4 - 5];
        z__[ipn4 - j4 - 5] = temp;
    }
}
