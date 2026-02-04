#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern real *vf;
extern real *vfw;
extern real *vl;
extern real *vlw;
extern real *dsigma;
extern integer *idxp;
extern integer i__1;
extern integer j;
extern integer jp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 >= 2) {
    for (int outer = 2; outer <= i__1; ++outer) {
        j = outer;
        jp = idxp[j];
        dsigma[j] = d__[jp];
        vfw[j] = vf[jp];
        vlw[j] = vl[jp];
    }
}
}
