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
integer k;
for (j = 1; j <= i__1; j += 2) {
    for (k = 0; k < 2 && (j + k) <= i__1; ++k) {
        integer idx = j + k;
        temp = z__[idx] / (delta[idx] * work[idx]);
        psi += z__[idx] * temp;
        dpsi += temp * temp;
        erretm += psi;
    }
}
}
