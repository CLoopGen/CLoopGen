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
    if (max_param >= 0) {
        for (k = 0; k <= max_param / 2; k++) {
            int64_t bits1 = sums[k][i];
            if (bits1 < bestbits) {
                bestbits = bits1;
                bestk = k;
            }
            int64_t bits2 = sums[max_param - k][i];
            if (bits2 < bestbits) {
                bestbits = bits2;
                bestk = max_param - k;
            }
        }
        if ((max_param + 1) % 2 == 1) {
            int64_t mid_bits = sums[max_param / 2 + 1][i];
            if (mid_bits < bestbits) {
                bestbits = mid_bits;
                bestk = max_param / 2 + 1;
            }
        }
    }
}
