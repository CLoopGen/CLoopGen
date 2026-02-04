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
    i__1 = 100000000;  // 100 million iterations for ~0.01s runtime
    coltyp = (integer*)calloc(i__1 + 1, sizeof(integer));
    if (!coltyp) {
        exit(1);
    }

    // Initialize coltyp values to be in range [1,4] to match ctot indexing
    for (integer idx = 2; idx <= i__1; ++idx) {
        coltyp[idx] = (idx % 4) + 1;  // ensures values 1,2,3,4
    }

    // Initialize ctot array to zero
    for (int i = 0; i < 4; ++i) {
        ctot[i] = 0;
    }
}