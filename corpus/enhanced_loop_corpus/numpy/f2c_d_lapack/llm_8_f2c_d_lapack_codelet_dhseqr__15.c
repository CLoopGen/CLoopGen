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
        wr[i__] = h__[i__ + i__ * h_dim1] + h__[i__ + (i__ + 1) * h_dim1] - h__[(i__ + 1) + i__ * h_dim1];
        wi[i__] = (h__[i__ + i__ * h_dim1] - h__[i__ + (i__ + 1) * h_dim1]) * 0.5;
    }
}
