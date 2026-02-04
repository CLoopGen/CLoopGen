#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *indx;
extern integer *indxc;
extern integer *indxp;
extern integer *coltyp;
extern integer i__1;
extern integer j;
extern integer ct;
extern integer js;
extern integer psm[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer offset;
    for (j = i__1; j >= 1; --j) {
        offset = coltyp[indxp[j]] - 1;
        indx[psm[offset]] = indxp[j];
        indxc[psm[offset]] = j;
        psm[offset] += 1;
    }
}
