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
    integer temp_val;
    for (j = 2; j <= i__1; ++j) {
        jp = idxp[j];
        ct = coltyp[jp];
        temp_val = psm[ct - 1];
        idxc[temp_val] = j;
        psm[ct - 1] = temp_val + 1;
    }
}
