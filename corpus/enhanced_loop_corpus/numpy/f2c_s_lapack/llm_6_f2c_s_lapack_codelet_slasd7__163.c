#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern real *vf;
extern real *beta;
extern integer i__1;
extern integer i__;
extern integer nlp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp;
    for (i__ = nlp2; i__ <= i__1; ++i__) {
        temp = *beta * vf[i__];
        z__[i__] = temp;
        vf[i__] = 0.F;
    }
}
