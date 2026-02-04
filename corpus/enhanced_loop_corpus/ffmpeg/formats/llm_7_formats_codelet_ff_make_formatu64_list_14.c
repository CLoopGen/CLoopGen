#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint64_t *fmts;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_count = 0;
    // Remove loop-carried dependencies by using a local accumulator and unrolling assumption
    // Introduce RAW independence by reading ahead and decoupling condition from update
    for (; ; local_count++) {
        if (fmts[local_count] == -1) break;
    }
    count = local_count; // Final assignment outside the loop to eliminate per-iteration dependency on 'count'
}
