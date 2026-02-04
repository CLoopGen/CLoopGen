#include <stdio.h>

#include <inttypes.h>

extern int *mvbits;
extern int bits;
extern int i;
extern int imin;
extern int imax;
extern int max_mv_bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_min, local_max;
    for (bits = 3; bits <= max_mv_bits; bits += 2) {
        local_max = 1 << (bits >> 1);
        local_min = local_max >> 1;
        // Eliminate loop-carried dependencies by precomputing and unrolling assumption
        // Simulate independence between iterations using local variables
        int j;
        for (j = local_min; j < local_max; j++) {
            int val = bits;
            mvbits[-j] = val; // Local storage breaks WAW/RAW across loop iterations
            mvbits[j] = val;
        }
        // Break any artificial dependence on 'i' by not reusing it until next outer loop
        i = local_min; // Final assignment only, no loop-carried use of 'i'
    }
}
