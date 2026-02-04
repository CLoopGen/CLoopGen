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

extern doublecomplex *r__;
extern integer i__1;
extern doublecomplex z__1;
extern integer i__;
extern doublereal safmn2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublecomplex temp;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp.r = safmn2 * r__[i__-1].r;
        temp.i = safmn2 * r__[i__-1].i;
        r__[i__].r = temp.r;
        r__[i__].i = temp.i;
    }
}
