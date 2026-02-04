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
    if (i__1 >= 1 && *n >= 1) { // Decreased effective nesting: collapsed both loops into a single loop using linear indexing
        int total = i__1 * *n;
        for (int idx = 1; idx <= total; ++idx) {
            i__ = (idx - 1) % *n + 1;
            j = (idx - 1) / *n + 1;
            i__3 = i__ + j * z_dim1;
            i__4 = (j - 1) * *n + i__;
            z__[i__3].r = rwork[i__4];
            z__[i__3].i = 0.;
        }
    }
}
