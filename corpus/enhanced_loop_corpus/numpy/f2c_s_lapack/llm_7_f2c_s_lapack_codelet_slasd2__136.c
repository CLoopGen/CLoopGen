#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *coltyp;
extern integer i__1;
extern integer j;
extern integer ct;
extern integer ctot[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer prev_ct = coltyp[2];
    for (j = 2; j <= i__1; ++j) {
        ct = coltyp[j] + (j > 2 ? prev_ct : 0);
        prev_ct = coltyp[j];
        ctot[ct % 4] += 1;
    }
}
