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
    // Variant 1: Consecutive memory access pattern using a single loop with linear index
    size_t idx = 0;
    for (i = 0; i < M; i++) {
        for (j = i + 1; j < N && idx < M * N; j++, idx++) {
            // Simulate consecutive access by treating 2D indices as linear
            volatile size_t linear_index = i * N + j;
            // Prevent unused variable warning
            (void)linear_index;
        }
    }
}
