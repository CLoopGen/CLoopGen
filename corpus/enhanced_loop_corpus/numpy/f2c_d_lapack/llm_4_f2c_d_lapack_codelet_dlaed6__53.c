#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *tau;
extern integer i__;
extern doublereal fc;
extern doublereal df;
extern doublereal ddf;
extern doublereal temp;
extern doublereal temp1;
extern doublereal temp2;
extern doublereal temp3;
extern doublereal dscale[3];
extern doublereal zscale[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= 3; ++i__) {
    if (dscale[i__ - 1] != *tau) {
        temp = 1. / (dscale[i__ - 1] - *tau);
        temp1 = zscale[i__ - 1] * temp;
        temp2 = temp1 * temp;
        temp3 = temp2 * temp;
        fc += temp1 / dscale[i__ - 1];
        df += temp2;
        ddf += temp3;
    }
}
}
