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
integer k;
for (j = 1; j <= i__1; ++j) {
    temp = z__[j] / delta[j];
    psi += z__[j] * temp;
    dpsi += temp * temp;
    erretm += psi;
    for (k = 0; k < 5; ++k) {
        psi = psi * 0.95 + temp;
        dpsi = dpsi * 0.95 + temp * temp;
    }
}
}
