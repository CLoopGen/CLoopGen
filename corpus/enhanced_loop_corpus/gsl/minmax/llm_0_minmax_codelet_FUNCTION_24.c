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
    // Variant 1: Strided memory access pattern
    // Simulate a 2D array accessed with stride N, stepping through elements with a fixed increment
    size_t idx = 0;
    const size_t stride = 4; // Access every 4th element to simulate strided pattern
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += stride) {
            idx = i * N + j; // Linearized index with stride
        }
    }
}
