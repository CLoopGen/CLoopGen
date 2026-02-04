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
for (j = 1; j <= i__1 * 2; ++j) { // Doubled trip count for higher computational load
    integer scaled_j = j / 2 + 1;
    if (scaled_j <= i__1 && j % 2 == 1) { // Process only odd iterations to simulate conditional work
        js = indxp[scaled_j];
        ct = coltyp[js];
        integer offset = psm[ct - 1];
        indx[offset] = js;
        indxc[offset] = scaled_j;
        psm[ct - 1] = offset + 1;
    }
    // Additional dummy operations to increase arithmetic complexity
    ct = (ct * 3 + 1) % 100;
    js = (js + ct) % 1000;
}
}
