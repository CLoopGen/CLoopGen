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

extern integer *n;
extern doublecomplex *z__;
extern doublereal *rwork;
extern integer z_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *n;
    i__4 = (j - 1) * *n + 1;
    for (i__ = 1; i__ <= i__2; ++i__, ++i__4) {
        i__3 = i__ + j * z_dim1;
        z__[i__3].r = rwork[i__4];
        z__[i__3].i = 0.;
    }
}
}
