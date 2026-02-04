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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal psi_local = psi;
    for (j = 1; j <= i__1; ++j) {
        psi_local = psi_local + z__[j] * z__[j] / delta[j];
    }
    psi = psi_local;
}
