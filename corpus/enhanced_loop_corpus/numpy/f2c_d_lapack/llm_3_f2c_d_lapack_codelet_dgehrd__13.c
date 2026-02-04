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
    // Variant 2: Consecutive write using pointer arithmetic for improved spatial locality
    integer start = ((1) >= (*ihi)) ? 1 : *ihi;
    integer count = (i__1 >= start) ? (i__1 - start + 1) : 0;
    doublereal *p = &tau[start];
    for (i__ = 0; i__ < count; ++i__) {
        p[i__] = 0.;
    }
}
