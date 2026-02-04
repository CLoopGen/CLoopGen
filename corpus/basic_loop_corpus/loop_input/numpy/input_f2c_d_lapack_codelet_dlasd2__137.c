#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *idxp;
integer *idxc;
integer *coltyp;
integer i__1;
integer j;
integer ct;
integer jp;
integer psm[4];

void init_vars() {
    // Define data size to make loop run ~0.01 seconds
    // Assume modern CPU can do ~1e9 iterations/sec -> aim for ~1e7 iterations
    i__1 = 10000000;  // 10 million iterations

    // Allocate idxp: index permutation array, values will be used as indices into coltyp
    idxp = (integer*)calloc(i__1 + 1, sizeof(integer));
    // Allocate coltyp: maps jp (value from idxp) to a type in [1,4]
    // We assume jp ranges from 1 to some max value; let's use up to 500000 distinct columns
    integer max_jp = 500000;
    coltyp = (integer*)malloc(max_jp * sizeof(integer));

    // Allocate idxc: must hold at least the number of times each coltyp is encountered
    // Since we have i__1 iterations and 4 types, worst-case one type gets all -> size i__1
    idxc = (integer*)malloc((i__1 + 1) * sizeof(integer));

    // Initialize psm: counts per coltype (1-indexed), so psm[ct-1] used
    // Initialize to base indices; assume we're appending to segments
    // Let’s initialize psm to zeros for simplicity (accumulating counts)
    psm[0] = 0;
    psm[1] = 0;
    psm[2] = 0;
    psm[3] = 0;

    // Initialize idxp with valid jp values in [1, max_jp]
    for (integer k = 2; k <= i__1; ++k) {
        idxp[k] = rand() % max_jp + 1;  // jp in [1, max_jp]
    }

    // Initialize coltyp: assign each jp a column type in [1,4]
    for (integer k = 1; k < max_jp; ++k) {
        coltyp[k] = rand() % 4 + 1;  // type in [1,4]
    }
}