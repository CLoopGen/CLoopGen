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
    for (j = 1; j <= i__1; j += 2) {
        if (j + 1 <= i__1) {
            psi += z__[j] * z__[j] / (delta[j] * work[j]) + 
                   z__[j+1] * z__[j+1] / (delta[j+1] * work[j+1]);
        } else {
            psi += z__[j] * z__[j] / (delta[j] * work[j]);
        }
    }
}
