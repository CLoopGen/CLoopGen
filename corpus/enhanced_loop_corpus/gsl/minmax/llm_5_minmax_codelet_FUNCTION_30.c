#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile uint64_t temp;
    uint64_t *sums = (uint64_t*)calloc(N, sizeof(uint64_t));
    for (j = 0; j < N; j++) {
        sums[j] = 0;
        for (i = 0; i < M; i++) {
            temp = i * j + 1;           // Eliminate cross-iteration dependencies
            sums[j] += temp;            // Independent accumulation per j (WAW dependency within j, but no loop-carried dep across i)
        }
    }
    free(sums);
}
