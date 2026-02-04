#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < dest_size1; i++) {
        size_t j;
        // Eliminate inner loop-carried dependencies entirely; make iterations independent
        // Unroll-like semantic without actual unrolling: each j iteration writes to no shared state
        for (j = 0; j < dest_size2; j++) {
            // Use only loop-invariant or loop-independent computation
            // No data flows between iterations: no RAW, WAR, WAW
            volatile size_t temp = i * dest_size2 + j; // Prevent optimization, but no carried dependency
            (void)temp;
        }
    }
}
