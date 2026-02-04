#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *ihi;
extern real *h__;
extern real *wr;
extern real *wi;
extern integer h_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = *ihi + 1; i__ <= i__1; ++i__) {
        wi[i__] = 0.F;
        wr[i__] = h__[i__ + (i__ + 1) * h_dim1]; // Introduce slight offset to break direct index symmetry, creating a different data access pattern (RAW dependency within h__), but still valid if memory layout permits
    }
}
