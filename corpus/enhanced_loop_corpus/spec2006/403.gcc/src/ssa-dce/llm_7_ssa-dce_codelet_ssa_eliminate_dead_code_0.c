#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int i;
extern int *pdom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_val = -3;
    for (i = 0; i < n_basic_blocks; ++i) {
        int j = i;                  // Local copy to break dependencies
        pdom[j] = local_val;        // Eliminate loop-carried dependency; each iteration writes independently
    }
    // No data dependencies between iterations; fully parallelizable
}
