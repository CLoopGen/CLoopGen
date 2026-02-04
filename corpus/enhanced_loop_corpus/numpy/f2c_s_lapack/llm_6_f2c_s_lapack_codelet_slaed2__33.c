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
    integer temp_js, temp_ct, temp_idx;
    for (j = 1; j <= i__1; ++j) {
        temp_js = indxp[j];
        temp_ct = coltyp[temp_js];
        temp_idx = psm[temp_ct - 1];
        indx[temp_idx] = temp_js;
        indxc[temp_idx] = j;
        psm[temp_ct - 1] = temp_idx + 1;
    }
}
