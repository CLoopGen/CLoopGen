#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int16_t *b;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array reindexing for better locality
    // Instead of strided writes to b[2*x] and b[2*x+1], write consecutively in increasing order
    // Also, precompute common terms and reorder computation for clarity and potential vectorization

    int limit = w2;
    for (x = 0; x < limit; x++) {
        int tmp_val = tmp[x];
        b[x * 2] = ((int)(tmp_val + 1U)) >> 1;

        int offset = x + w2;
        int b_val = b[offset];
        int weighted_sum = (9U * tmp_val + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8);
        int filtered = ((unsigned int)b_val + ((int)(weighted_sum >> 4))) + 1U;
        b[x * 2 + 1] = filtered >> 1;
    }
}
