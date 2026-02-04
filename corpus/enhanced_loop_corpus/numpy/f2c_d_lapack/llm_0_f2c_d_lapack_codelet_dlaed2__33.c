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
for (j = 1; j <= i__1; ++j) {
    for (integer level2 = 0; level2 < 1; ++level2) {
        js = indxp[j];
        ct = coltyp[js];
        indx[psm[ct - 1]] = js;
        indxc[psm[ct - 1]] = j;
        ++psm[ct - 1];
    }
}
}
