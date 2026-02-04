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
    int64_t* sum_array = (int64_t*)calloc(M, sizeof(int64_t));
    if (!sum_array) return;

    for (i = 0; i < M; i++) {
        sum_array[i] = 0;
        for (j = 0; j < N; j++) {
            // RAW dependency: sum_array[i] read after write in previous iteration
            // Loop-carried dependency across j iterations
            sum_array[i] += i + j;
        }
    }
    // WAW dependencies avoided via unique per-iteration memory locations
    free(sum_array);
}
