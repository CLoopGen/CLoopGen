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
extern real dpsi;
extern real temp;
extern real erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    if (j + 1 <= i__1) {
        // Unroll with stride of 2: process two elements per iteration
        temp = z__[j] / (delta[j] * work[j]);
        psi += z__[j] * temp;
        dpsi += temp * temp;
        erretm += psi;

        temp = z__[j+1] / (delta[j+1] * work[j+1]);
        psi += z__[j+1] * temp;
        dpsi += temp * temp;
        erretm += psi;
    } else {
        // Handle odd-sized tail
        temp = z__[j] / (delta[j] * work[j]);
        psi += z__[j] * temp;
        dpsi += temp * temp;
        erretm += psi;
    }
}
}
