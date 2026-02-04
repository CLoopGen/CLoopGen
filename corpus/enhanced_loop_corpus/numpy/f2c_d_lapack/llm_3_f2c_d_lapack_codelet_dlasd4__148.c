#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal psi;
extern doublereal dpsi;
extern doublereal temp;
extern doublereal erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    if (j + 1 <= i__1) {
        // Process two elements per iteration (consecutive access)
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
