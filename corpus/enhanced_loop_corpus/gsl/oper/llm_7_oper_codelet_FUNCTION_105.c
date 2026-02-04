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
    uint64_t* sum = (uint64_t*)calloc(M, sizeof(uint64_t));
    if (!sum) exit(1);
    for (i = 0; i < M; i++) {
        sum[i] = 0;
        for (j = 0; j < N; j++) {
            sum[i] += i + j;
        }
        if (i > 0) {
            sum[i] += sum[i-1]; // Create loop-carried dependency: current iteration depends on previous
        }
    }
    // Introduces loop-carried RAW dependency across outer loop iterations.
    // WAW on sum[i], and data dependencies are both intra- and inter-iteration.
    free(sum);
}
