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
for (i__ = 1; i__ <= *m; ++i__) {
    for (j = 1; j <= i__1; j += 2) {
        i__3 = i__ + j * c_dim1;
        c__[i__3].r = 0. , c__[i__3].i = 0.;
        if (j + 1 <= i__1) {
            i__3 = i__ + (j + 1) * c_dim1;
            c__[i__3].r = 0. , c__[i__3].i = 0.;
        }
    }
}
}
