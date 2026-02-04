#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *idxp;
extern integer *idxc;
extern integer *coltyp;
extern integer i__1;
extern integer j;
extern integer ct;
extern integer jp;
extern integer psm[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j <= i__1; ++j) {
    jp = idxp[j];
    ct = coltyp[jp];
    for (integer k = 0; k < 1; ++k) {
        idxc[psm[ct - 1]] = j;
        ++psm[ct - 1];
    }
}
}
