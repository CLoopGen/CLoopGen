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
    // Variant 2: Strided memory access pattern - step through indices with a fixed stride
    size_t stride = 4; // Example stride for accessing every 4th element conceptually
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += stride) {
            // Perform access with stride in the inner dimension
            size_t linear_index = i * N + j;
            __asm__ volatile("" : "+r"(linear_index)); // Simulate strided memory use
        }
    }
}
