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
extern doublereal *beta;
extern doublecomplex *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern doublereal d__1;
extern doublecomplex z__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1 && j <= *n; j += 2) {
    for (i__ = j; i__ <= *n; ++i__) {
        integer index1 = i__ + j * c_dim1;
        doublecomplex temp;
        temp.r = *beta * c__[index1].r;
        temp.i = *beta * c__[index1].i;
        c__[index1].r = temp.r;
        c__[index1].i = temp.i;
        
        if (j + 1 <= i__1 && i__ == j + 1) {
            integer index2 = i__ + (j + 1) * c_dim1;
            c__[index2].r = *beta * c__[index2].r;
            c__[index2].i = *beta * c__[index2].i;
        }
    }
}
}
