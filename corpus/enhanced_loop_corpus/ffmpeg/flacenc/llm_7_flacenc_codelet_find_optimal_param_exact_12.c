#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t sums[32][256];
extern int i;
extern int max_param;
extern int bestk;
extern int64_t bestbits;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    bestbits = sums[0][i];
    bestk = 0;
    for (k = 1; k <= max_param; k++) {
        int64_t bits = sums[k][i];
        int64_t prev_bits = sums[k-1][i];
        if (bits < prev_bits && bits < bestbits) {
            bestbits = bits;
            bestk = k;
        }
    }
}
