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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1 / 2; ++j) {
        doublereal temp1 = z__[j] * z__[j];
        doublereal temp2 = delta[j] * work[j];
        if (temp2 != 0.0) {
            psi += temp1 / temp2;
        }
    }
}
