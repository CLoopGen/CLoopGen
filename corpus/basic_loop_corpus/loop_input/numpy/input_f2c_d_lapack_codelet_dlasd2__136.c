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
    i__1 = 50000000; // Adjusted for ~0.01 sec runtime

    coltyp = (integer*)malloc((i__1 + 1) * sizeof(integer));
    if (!coltyp) {
        exit(1);
    }

    for (integer idx = 2; idx <= i__1; ++idx) {
        coltyp[idx] = rand() % 4 + 1;
    }

    ctot[0] = 0;
    ctot[1] = 0;
    ctot[2] = 0;
    ctot[3] = 0;
}