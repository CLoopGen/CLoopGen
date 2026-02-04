#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *ihi;
extern doublereal *tau;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (*ihi < 1) {
        for (i__ = 1; i__ <= i__1; ++i__) {
            tau[i__] = 0.;
        }
    } else {
        for (i__ = *ihi; i__ <= i__1; ++i__) {
            tau[i__] = 0.;
        }
    }
}
