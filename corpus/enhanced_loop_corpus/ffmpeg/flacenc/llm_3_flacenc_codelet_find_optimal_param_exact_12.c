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
    // Variant 2: Consecutive memory access by flipping the access pattern to favor cache locality
    // Assume i varies less frequently; precompute base pointer to improve access pattern
    uint64_t* col_sums = &sums[0][i]; // Base of column i across all k
    for (k = 0; k <= max_param; k++) {
        int64_t bits = (int64_t)col_sums[k * 256]; // Access as if row-major: [k][i] -> index k*256 + i, but here we fix i and vary k
        if (bits < bestbits) {
            bestbits = bits;
            bestk = k;
        }
    }
}
