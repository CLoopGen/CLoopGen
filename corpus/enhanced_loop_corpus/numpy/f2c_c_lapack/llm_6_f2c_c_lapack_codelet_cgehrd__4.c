#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *ihi;
extern singlecomplex *tau;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    singlecomplex temp;
    for (i__ = ((1) >= (*ihi) ? (1) : (*ihi)); i__ <= i__1; ++i__) {
        i__2 = i__;
        temp.r = tau[i__2].r;
        temp.i = tau[i__2].i;
        tau[i__2].r = temp.r + 0.F;
        tau[i__2].i = temp.i + 0.F;
    }
}
