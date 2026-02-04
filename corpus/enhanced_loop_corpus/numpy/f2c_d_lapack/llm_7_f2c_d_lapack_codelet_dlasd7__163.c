#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern doublereal *vf;
extern doublereal *beta;
extern integer i__1;
extern integer i__;
extern integer nlp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp_beta = *beta;
    for (i__ = nlp2; i__ <= i__1; ++i__) {
        doublereal temp_vf = vf[i__];
        z__[i__] = temp_beta * temp_vf;
        vf[i__] = 0.;
    }
}
