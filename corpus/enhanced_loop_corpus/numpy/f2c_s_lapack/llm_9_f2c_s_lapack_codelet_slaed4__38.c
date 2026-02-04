#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern real *delta;
extern integer i__1;
extern integer j;
extern real psi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 2; j <= i__1; j += 2) {
        real temp1 = z__[j-1] * z__[j-1] / delta[j-1];
        real temp2 = z__[j] * z__[j] / delta[j];
        psi += temp1 + temp2;
    }
    if (i__1 % 2 == 1) {
        psi += z__[i__1] * z__[i__1] / delta[i__1];
    }
}
