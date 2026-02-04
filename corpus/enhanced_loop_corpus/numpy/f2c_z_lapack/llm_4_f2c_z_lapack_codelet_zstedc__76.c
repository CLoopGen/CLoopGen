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
for (i__ = 1; i__ <= *n; ++i__) {
    for (j = 1; j <= i__1; ++j) {
        i__3 = i__ + j * z_dim1;
        i__4 = i__ + (j - 1) * *n;
        z__[i__3].r = rwork[i__4];
        z__[i__3].i = 0.;
    }
}
}
