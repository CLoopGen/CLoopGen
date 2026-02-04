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
    }

    // Eliminate loop-carried dependencies by making each iteration independent
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            data[i][j] = i + j; // No loop-carried dependency: each write is to unique memory location
        }
    }

    // Clean up to avoid leaks (still part of valid execution)
    for (i = 0; i < M; i++) {
        free(data[i]);
    }
    free(data);
}
