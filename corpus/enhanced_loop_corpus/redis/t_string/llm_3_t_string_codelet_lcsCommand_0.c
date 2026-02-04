#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef char *sds;

extern sds a;
extern sds b;
extern uint32_t alen;
extern uint32_t blen;
extern uint32_t *lcs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Transposed Indexing (Column-major Simulation)
    for (uint32_t j = 0; j <= blen; j++) {
        for (uint32_t i = 0; i <= alen; i++) {
            uint32_t index = j * (alen + 1) + i;  // Transposed layout: column-major order in storage
            if (i == 0 || j == 0) {
                lcs[index] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                uint32_t prev_index = (j - 1) * (alen + 1) + (i - 1);
                lcs[index] = lcs[prev_index] + 1;
            } else {
                uint32_t lcs1 = lcs[index - 1];                      // top (same column, previous row)
                uint32_t lcs2 = (j > 0) ? lcs[index - (alen + 1)] : 0; // left (previous column, same row)
                lcs[index] = lcs1 > lcs2 ? lcs1 : lcs2;
            }
        }
    }
}
