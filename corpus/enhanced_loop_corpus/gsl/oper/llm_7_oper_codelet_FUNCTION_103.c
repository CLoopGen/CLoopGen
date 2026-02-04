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
        for (j = 0; j < N; j++) {
            // Introduce RAW: each access to sum_array[i] depends on prior writes
            // Loop-carried dependency via memory location sum_array[i]
            sum_array[i] += (i + j) * (i + j);
        }
    }

    // Eliminate local dependencies but create memory-based WAW
    // by writing distinct indices independently
    for (i = 0; i < M; i++) {
        sum_array[i] *= 2;
    }

    free(sum_array);
}
