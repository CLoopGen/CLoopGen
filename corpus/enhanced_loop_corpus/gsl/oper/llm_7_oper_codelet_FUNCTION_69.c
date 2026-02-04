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
    for (i = 0; i < M; i++) {
        sum_array[i] = 0;
        for (j = 0; j < N; j++) {
            sum_array[i] += (i + 1) * (j + 1);
        }
    }
    // Introduce loop-carried dependence: each sum_array[i] accumulates values dependent on both i and j
    // RAW dependencies: use of i, j in computation after their definition
    // WAW: each write to sum_array[i] overwrites previous partial sum
    // WAR avoided due to sequential access per i
    // Memory dependence introduced across inner loop iterations (carried by j-loop reduction)
    free(sum_array);
}
