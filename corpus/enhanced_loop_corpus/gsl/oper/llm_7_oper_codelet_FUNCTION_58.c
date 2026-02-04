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
    int64_t **data = (int64_t**)malloc(M * sizeof(int64_t*));
    for (i = 0; i < M; i++) {
        data[i] = (int64_t*)calloc(N, sizeof(int64_t));
        for (j = 0; j < N; j++) {
            data[i][j] = i + j;
            // Independent writes — no loop-carried dependencies
            // All dependencies are within iteration (no RAW/WAR/WAW across iterations)
        }
    }
    // Eliminated loop-carried dependencies by making each iteration independent
    // Data stored in heap-allocated 2D array with row-major access
    for (i = 0; i < M; i++) free(data[i]);
    free(data);
}
