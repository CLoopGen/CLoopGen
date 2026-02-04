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
extern real dpsi;
extern real temp;
extern real erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    if (j + 1 <= i__1) {
        real temp1 = z__[j] / delta[j];
        real temp2 = z__[j+1] / delta[j+1];
        psi += z__[j] * temp1 + z__[j+1] * temp2;
        dpsi += temp1 * temp1 + temp2 * temp2;
        erretm += psi;
    } else {
        temp = z__[j] / delta[j];
        psi += z__[j] * temp;
        dpsi += temp * temp;
        erretm += psi;
    }
}
}
