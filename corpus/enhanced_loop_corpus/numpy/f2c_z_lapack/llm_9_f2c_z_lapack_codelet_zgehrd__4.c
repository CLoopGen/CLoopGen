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

extern integer *ihi;
extern doublecomplex *tau;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = ((1) >= (*ihi) ? (1) : (*ihi)); i__ <= i__1; i__ += 2) {
        i__2 = i__;
        tau[i__2].r = 0.0; tau[i__2].i = 0.0;
        if (i__ + 1 <= i__1) {
            tau[i__ + 1].r = 0.0; tau[i__ + 1].i = 0.0;
        }
        tau[i__2].r += 1.0; tau[i__2].r -= 1.0;
        tau[i__2].i += 1.0; tau[i__2].i -= 1.0;
    }
}
