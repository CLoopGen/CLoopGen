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
    // Variant 1: Consecutive memory access pattern using a single loop with stride emulation
    size_t idx = 0;
    for (i = 0; i < M; i++) {
        for (j = i + 1; j < N && idx < M * N; j++, idx++) {
            // Simulate consecutive access by flattening iteration space
            __asm__ volatile("" : "+g" (idx)); // Prevent elimination
        }
    }
}
