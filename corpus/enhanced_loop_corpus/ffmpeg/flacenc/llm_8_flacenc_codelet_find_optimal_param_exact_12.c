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
    for (k = 0; k <= max_param; k += 2) {
        int64_t bits1 = sums[k][i];
        int64_t bits2 = (k + 1 <= max_param) ? sums[k + 1][i] : bits1;
        if (bits1 < bestbits) {
            bestbits = bits1;
            bestk = k;
        }
        if (bits2 < bestbits && (k + 1 <= max_param)) {
            bestbits = bits2;
            bestk = k + 1;
        }
    }
}
