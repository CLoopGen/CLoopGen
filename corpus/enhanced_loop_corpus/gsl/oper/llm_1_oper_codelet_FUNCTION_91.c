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
    // Variant 2: Strided memory access pattern - traverse columns with fixed stride across rows
    size_t stride = N > 4 ? N / 4 : 1; // Example stride to create non-unit step
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += stride) {
            // Ensure j stays within bounds after stride jump
            if (j >= N) break;
            // Simulate strided access, e.g., in a 2D array: arr[i][j], then arr[i][j+stride]
            volatile size_t index = i * N + j;
        }
    }
}
