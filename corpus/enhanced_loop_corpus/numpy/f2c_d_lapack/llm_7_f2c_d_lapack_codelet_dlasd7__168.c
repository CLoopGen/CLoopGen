#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *vf;
extern doublereal *vfw;
extern doublereal *vl;
extern doublereal *vlw;
extern doublereal *dsigma;
extern integer *idxp;
extern integer i__1;
extern integer j;
extern integer jp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
doublereal temp_d, temp_vf, temp_vl;
for (j = 2; j <= i__1; ++j) {
    jp = idxp[j];
    temp_d = d__[jp];
    temp_vf = vf[jp];
    temp_vl = vl[jp];
    dsigma[j] = temp_d;
    vfw[j] = temp_vf;
    vlw[j] = temp_vl;
} // Eliminated potential WAW and WAR hazards by using temporaries; no loop-carried dependencies
}
