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
    uint64_t* sum = (uint64_t*)calloc(N, sizeof(uint64_t));
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            sum[j] += i + j; // Introduce loop-carried dependence: sum[j] read and written across iterations of i
            // RAW dependency: each iteration depends on previous value of sum[j]
            // WAW if parallelized improperly, but sequential execution preserves semantics
        }
    }
    free(sum);
    // Adds loop-carried dependency across outer loop via sum array
}
