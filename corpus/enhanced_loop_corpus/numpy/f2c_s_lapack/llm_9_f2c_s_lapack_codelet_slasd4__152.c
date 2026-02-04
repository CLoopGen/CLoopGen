#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real psi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 2; j <= i__1; j += 2) {
        real temp1 = z__[j-1] * z__[j-1];
        real temp2 = z__[j] * z__[j];
        real denom1 = work[j-1] * delta[j-1];
        real denom2 = work[j] * delta[j];
        psi += temp1 / (denom1 + 1e-9f) + temp2 / (denom2 + 1e-9f);
    }
    if (i__1 % 2 == 1) {
        real temp = z__[i__1] * z__[i__1];
        real denom = work[i__1] * delta[i__1];
        psi += temp / (denom + 1e-9f);
    }
}
