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
    uint64_t **data = (uint64_t**)malloc(M * sizeof(uint64_t*));
    for (i = 0; i < M; i++) {
        data[i] = (uint64_t*)calloc(N, sizeof(uint64_t));
    }
    // Initialize with loop-carried dependence: each element depends on previous in row
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (j == 0) {
                data[i][j] = i + 1;
            } else {
                data[i][j] = data[i][j-1] + 1; // RAW dependence: current depends on previous j
            }
        }
    }
    // Add WAR and WAW by reversing order to demonstrate different dependency patterns
    for (i = 0; i < M; i++) {
        for (j = N - 1; j < N; j--) { // Reverse inner loop using unsigned wrap guard
            data[i][j] = data[i][j] * 2; // WAW on same element, WAR due to reverse access
            if (j > 0) {
                data[i][j-1] = data[i][j] + 1;
            }
        }
    }
    // Clean up to avoid memory leaks (required for correctness in real use)
    for (i = 0; i < M; i++) {
        free(data[i]);
    }
    free(data);
}
