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
    integer temp_r = 0, temp_i = 0;
    for (i__ = ((1) >= (*ihi) ? (1) : (*ihi)); i__ <= i__1; ++i__) {
        temp_r += tau[i__].r;
        temp_i += tau[i__].i;
        tau[i__].r = 0.0;
        tau[i__].i = 0.0;
    }
    // Introduce a post-loop write that depends on accumulated values (WAW and RAW dependencies introduced)
    if (i__1 >= *ihi) {
        tau[*ihi].r = temp_r;
        tau[*ihi].i = temp_i;
    }
}
