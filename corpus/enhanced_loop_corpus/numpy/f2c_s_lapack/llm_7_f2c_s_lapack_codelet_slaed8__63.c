#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern integer *indxq;
extern real *dlamda;
extern integer *perm;
extern integer *indxp;
extern integer *indx;
extern integer i__1;
extern integer j;
extern integer jp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        integer temp_indxp = indxp[j];
        real temp_d_value = d__[temp_indxp];
        integer temp_indx = indx[temp_indxp];
        // Eliminate potential WAW and WAR hazards by using temporaries and reordering independent operations
        perm[j] = indxq[temp_indx];
        dlamda[j] = temp_d_value;
    }
}
