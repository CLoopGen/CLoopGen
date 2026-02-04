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
    uint64_t* sum_array = (uint64_t*)calloc(M, sizeof(uint64_t));
    if (!sum_array) return;

    for (i = 0; i < M; i++) {
        sum_array[i] = 0;
        for (j = 0; j < N; j++) {
            sum_array[i] += (i + 1) * (j + 1); // Flow (RAW) dependency: each iteration writes sum_array[i], read in next j
        }
    }
    // Introduces loop-carried flow (RAW) dependence within inner loop via sum_array[i]
    // Eliminates any potential for inner loop vectorization due to cumulative dependency
    free(sum_array);
}
