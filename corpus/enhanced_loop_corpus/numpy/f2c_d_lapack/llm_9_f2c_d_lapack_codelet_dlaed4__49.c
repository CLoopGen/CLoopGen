#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal psi;
extern doublereal dpsi;
extern doublereal temp;
extern doublereal erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer stride = 2;
for (j = 1; j <= i__1; j += stride) {
    temp = z__[j] / delta[j];
    psi += z__[j] * temp;
    dpsi += temp * temp;
    erretm += psi;
    if (j + 1 <= i__1) {  // Simulate unrolled body without actual full unrolling
        temp = z__[j+1] / delta[j+1];
        psi += z__[j+1] * temp;
        dpsi += temp * temp;
        erretm += psi;
    }
}
}
