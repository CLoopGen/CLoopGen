#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *coltyp;
integer i__1;
integer j;
integer ct;
integer ctot[4];

void init_vars() {
    i__1 = 67108864; // ~67 million iterations for ~0.01 sec runtime
    coltyp = (integer*)aligned_alloc(32, i__1 * sizeof(integer));
    
    for (int idx = 0; idx < i__1; ++idx) {
        coltyp[idx] = rand() % 4 + 1; // values from 1 to 4
    }

    ctot[0] = 0;
    ctot[1] = 0;
    ctot[2] = 0;
    ctot[3] = 0;
}