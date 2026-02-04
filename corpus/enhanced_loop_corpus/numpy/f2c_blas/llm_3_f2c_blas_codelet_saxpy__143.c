#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sa;
extern real *sx;
extern real *sy;
extern integer i__1;
extern integer i__;
extern integer mp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every 8th element in a blocked fashion
    real sa_val = *sa;
    integer stride = 8;
    // Process four vectors with stride to simulate non-unit strided access
    for (i__ = mp1; i__ <= i__1; i__ += stride) {
        if (i__ <= i__1) {
            sy[i__] += sa_val * sx[i__];
        }
        if (i__ + 2 <= i__1) {
            sy[i__ + 2] += sa_val * sx[i__ + 2];
        }
        if (i__ + 4 <= i__1) {
            sy[i__ + 4] += sa_val * sx[i__ + 4];
        }
        if (i__ + 6 <= i__1) {
            sy[i__ + 6] += sa_val * sx[i__ + 6];
        }
    }
}
