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
    if (j % 2 == 0) {
        i__2 = *n;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__ + j * z_dim1;
            i__4 = (j - 1) * *n + i__;
            z__[i__3].r = rwork[i__4];
            z__[i__3].i = 0.;
        }
    }
}
}
