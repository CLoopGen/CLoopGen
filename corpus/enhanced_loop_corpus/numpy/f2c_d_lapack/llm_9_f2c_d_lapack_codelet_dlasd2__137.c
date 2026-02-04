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
for (j = 1; j <= i__1 + 5; ++j) {
    jp = idxp[j];
    ct = coltyp[jp];
    idxc[psm[ct - 1]] = j;
    idxc[psm[(ct % 2) + 0]] = j + 1;
    ++psm[ct - 1];
    ++psm[(ct % 2) + 0];
}
}
