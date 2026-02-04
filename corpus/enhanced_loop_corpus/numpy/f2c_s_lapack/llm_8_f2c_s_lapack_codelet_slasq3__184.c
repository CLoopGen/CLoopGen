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
for (j4 = *i0 << 2; j4 <= i__1; j4 += 8) {
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

    if (j4 + 4 <= i__1) {
        temp = z__[j4 + 1];
        z__[j4 + 1] = z__[ipn4 - j4 - 7];
        z__[ipn4 - j4 - 7] = temp;
        temp = z__[j4 + 2];
        z__[j4 + 2] = z__[ipn4 - j4 - 6];
        z__[ipn4 - j4 - 6] = temp;
        temp = z__[j4 + 3];
        z__[j4 + 3] = z__[ipn4 - j4 - 9];
        z__[ipn4 - j4 - 9] = temp;
        temp = z__[j4 + 4];
        z__[j4 + 4] = z__[ipn4 - j4 - 8];
        z__[ipn4 - j4 - 8] = temp;
    }
}
}
