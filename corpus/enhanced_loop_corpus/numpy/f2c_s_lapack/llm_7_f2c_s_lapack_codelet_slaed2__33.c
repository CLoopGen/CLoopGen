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
        integer js_val = indxp[j];
        integer ct_val = coltyp[js_val];
        offset = psm[ct_val - 1];
        indx[offset] = js_val;
        indxc[offset] = j;
        psm[ct_val - 1] = offset + 1;
    }
}
