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
for (k = 0; k <= max_param; k++) {
    int64_t bits = sums[k][i];
    if (bits < bestbits) {
        bestbits = bits;
        bestk = k;
    }
}

}
