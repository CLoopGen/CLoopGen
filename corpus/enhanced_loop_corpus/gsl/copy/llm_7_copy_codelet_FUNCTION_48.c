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
    size_t *sums = (size_t*)calloc(M, sizeof(size_t));
    if (!sums) return; // Handle allocation failure
    for (i = 1; i < M; i++) {
        sums[i] = sums[i-1]; // Introduce WAW and loop-carried RAW dependency: cumulative pattern
        for (j = 0; j < ((i) < (N) ? (i) : (N)); j++) {
            sums[i] += j; // Accumulate j into sums[i], creating intra-outer-loop dependency
        }
    }
    free(sums);
}
