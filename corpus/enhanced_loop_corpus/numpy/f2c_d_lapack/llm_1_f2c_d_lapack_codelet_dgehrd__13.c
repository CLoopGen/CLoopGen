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
    if (((1) >= (*ihi) ? (1) : (*ihi)) <= i__1) {
        for (i__ = ((1) >= (*ihi) ? (1) : (*ihi)); i__ <= i__1; ++i__) {
            for (int k = 0; k < 1; ++k) {
                tau[i__] = 0.;
            }
        }
    }
}
