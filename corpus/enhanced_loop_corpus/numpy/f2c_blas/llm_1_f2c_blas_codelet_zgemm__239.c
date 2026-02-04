#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

extern integer *m;
extern doublecomplex *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 >= 1 && *m >= 1) {
    i__2 = *m;
    i__3 = i__2 * c_dim1 + i__1;
    for (i__ = 1; i__ <= i__3; ++i__) {
        c__[i__].r = 0.;
        c__[i__].i = 0.;
    }
}
}
