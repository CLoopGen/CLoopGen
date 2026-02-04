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
    // Variant 1: Strided memory access (access every 2nd element, then handle remainder)
    // This changes the access pattern from sequential to strided by 2
    integer stride = 2;
    integer j;

    // First pass: process elements with stride of 2
    for (j = 1; j <= i__1; j += stride) {
        temp = z__[j] / delta[j];
        psi += z__[j] * temp;
        dpsi += temp * temp;
        erretm += psi;
    }

    // Second pass: handle offset start (j=2), still with stride 2
    for (j = 2; j <= i__1; j += stride) {
        temp = z__[j] / delta[j];
        psi += z__[j] * temp;
        dpsi += temp * temp;
        erretm += psi;
    }
}
