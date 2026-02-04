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
    js = indxp[j];
    ct = coltyp[js];
    integer offset = psm[ct - 1];
    indx[offset] = js;
    indxc[offset] = j;
    psm[ct - 1] = offset + 1;

    if (j % 3 == 0) {
        integer temp = indx[j];
        if (temp > 0 && temp <= i__1) {
            integer ct2 = coltyp[temp];
            psm[ct2 - 1] += 2;
        }
    }
}
}
