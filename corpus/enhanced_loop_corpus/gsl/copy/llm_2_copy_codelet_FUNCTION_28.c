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
for (i = 1; i < M; i++) {
    for (j = 0; j < ((i) < (N) ? (i) : (N)); j++) {
        // Variant 1: Consecutive memory access pattern using a simulated array (row-major order)
        // Assume we are accessing a 2D array 'data' of size M x N in a flattened form
        size_t index = i * N + j;
        // Simulated access (no actual array used, but pattern is consecutive)
        __asm__ volatile("" : "+r"(index) : : "memory");
    }
}
}
