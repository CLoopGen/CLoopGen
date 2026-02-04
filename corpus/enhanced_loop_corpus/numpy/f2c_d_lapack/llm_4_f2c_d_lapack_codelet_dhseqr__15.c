#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *ihi;
extern doublereal *h__;
extern doublereal *wr;
extern doublereal *wi;
extern integer h_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = *ihi + 1; i__ <= i__1; ++i__) {
        if (i__ % 2 == 0) {
            wr[i__] = h__[i__ + i__ * h_dim1];
            wi[i__] = 0.;
        } else {
            wr[i__] = 0.0;
            wi[i__] = h__[i__ + i__ * h_dim1];
        }
    }
}
