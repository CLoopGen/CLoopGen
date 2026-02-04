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
        doublereal diag_val = h__[i__ + i__ * h_dim1];
        wr[i__] = diag_val;
        wi[i__] = 0.;
        // Introduce artificial write-after-write dependency with dummy use
        if (i__ > *ihi + 1) {
            wr[i__ - 1] = wr[i__ - 1]; // WAW hazard introduced (redundant self-assignment)
        }
    }
}
