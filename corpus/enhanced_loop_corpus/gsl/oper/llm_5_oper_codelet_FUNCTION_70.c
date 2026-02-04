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
    uint64_t* array = (uint64_t*)calloc(N, sizeof(uint64_t));
    if (!array) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            array[j] = i + array[(j > 0) ? j - 1 : 0]; // RAW dependency: array[j-1] -> array[j]
            // Loop-carried dependence across j: each iteration depends on previous j
            // This creates a loop-carried flow dependence in the inner loop.
        }
    }
    free(array);
}
