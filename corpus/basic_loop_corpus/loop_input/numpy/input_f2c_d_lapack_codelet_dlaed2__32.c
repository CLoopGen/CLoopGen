#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;

integer *coltyp;
integer i__1;
integer j;
integer ct;
integer ctot[4];

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    i__1 = (integer)(data_size / sizeof(integer));
    coltyp = (integer *)aligned_alloc(32, (i__1 + 1) * sizeof(integer));
    if (!coltyp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 1; idx <= i__1; ++idx) {
        coltyp[idx] = (rand() % 4) + 1; // values 1 to 4
    }

    ctot[0] = 0;
    ctot[1] = 0;
    ctot[2] = 0;
    ctot[3] = 0;
}