#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;

integer *indxq;
integer *indx;
integer *indxc;
integer i__1;
integer i__;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Empirical testing suggests ~8M elements gives appropriate timing on modern CPUs
    i__1 = 8000000;
    
    // Allocate arrays with proper bounds
    indxq = (integer*)calloc(i__1 + 1, sizeof(integer));
    indx  = (integer*)calloc(i__1 + 1, sizeof(integer));
    indxc = (integer*)calloc(i__1 + 1, sizeof(integer));
    
    if (!indxq || !indx || !indxc) {
        // If allocation fails, ensure graceful failure
        if (indxq) free(indxq);
        if (indx) free(indx);
        if (indxc) free(indxc);
        exit(1);
    }
    
    // Initialize indxc with valid indices into indxq (0 to i__1)
    // Use deterministic pattern to avoid out-of-bounds access
    for (int j = 1; j <= i__1; ++j) {
        indxc[j] = (j * 78901) % (i__1 + 1);  // Ensure within range [0, i__1]
    }
    
    // Initialize indxq with non-zero test values
    for (int j = 0; j <= i__1; ++j) {
        indxq[j] = j * 321;
    }
    
    // Initialize indx to detect changes after loop execution
    for (int j = 0; j <= i__1; ++j) {
        indx[j] = -1;
    }
}