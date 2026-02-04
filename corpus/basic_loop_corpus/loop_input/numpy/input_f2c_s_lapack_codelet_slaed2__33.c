#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;

integer *indx;
integer *indxc;
integer *indxp;
integer *coltyp;
integer i__1;
integer j;
integer ct;
integer js;
integer psm[4];

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Based on typical performance, we'll target around 2-4 million iterations
    i__1 = 3000000;  // Approximately 3M iterations

    // Allocate arrays with sufficient size
    // indxp should have at least i__1+1 elements (1-indexed)
    indxp = (integer*)malloc((i__1 + 1) * sizeof(integer));
    
    // coltyp needs to be large enough to handle indices from indxp
    // Assuming maximum value in indxp is roughly i__1
    coltyp = (integer*)malloc((i__1 + 1000) * sizeof(integer));
    
    // indx and indxc need to accommodate writes based on psm counters
    // psm tracks counts per category (4 categories), so total size should be at least i__1
    indx = (integer*)malloc(i__1 * sizeof(integer));
    indxc = (integer*)malloc(i__1 * sizeof(integer));

    // Initialize psm counters to zero
    psm[0] = 0;
    psm[1] = 0;
    psm[2] = 0;
    psm[3] = 0;

    // Seed random number generator for realistic data distribution
    srand(12345);

    // Initialize indxp: permutation-like array with values in valid range
    for (int idx = 1; idx <= i__1; ++idx) {
        indxp[idx] = rand() % (i__1 / 4) + 1;  // Values from 1 to ~750k
    }

    // Initialize coltyp: map each index to one of 4 types (1-4)
    for (int idx = 1; idx <= i__1 / 4 + 100; ++idx) {
        coltyp[idx] = rand() % 4 + 1;  // Values from 1 to 4
    }

    // Ensure no out-of-bounds access by limiting how much psm can grow
    // With i__1 iterations and 4 categories, average ~750k per category
    // Our indx/indxc arrays are sized to handle this
}