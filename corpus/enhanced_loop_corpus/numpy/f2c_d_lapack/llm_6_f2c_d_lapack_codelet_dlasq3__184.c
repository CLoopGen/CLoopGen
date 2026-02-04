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
    integer k;
    for (j4 = *i0 << 2; j4 <= i__1; j4 += 4) {
        k = ipn4 - j4;
        temp = z__[j4 - 3];
        z__[j4 - 3] = z__[k - 3];
        z__[k - 3] = temp;
        temp = z__[j4 - 2];
        z__[j4 - 2] = z__[k - 2];
        z__[k - 2] = temp;
        temp = z__[j4 - 1];
        z__[j4 - 1] = z__[k - 5];
        z__[k - 5] = temp;
        temp = z__[j4];
        z__[j4] = z__[k - 4];
        z__[k - 4] = temp;
    }
}
