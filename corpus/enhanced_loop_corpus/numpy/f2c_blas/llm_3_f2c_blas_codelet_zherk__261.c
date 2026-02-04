#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1 * c_dim1; j += c_dim1) {
    for (i__ = 1; i__ <= j / c_dim1; ++i__) {
        i__3 = i__ + j;
        c__[i__3].r = 0. , c__[i__3].i = 0.;
    }
}
}
