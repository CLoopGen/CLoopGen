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
    // Variant 2: Strided memory access pattern - traverse column-wise with large stride
    // Simulating access to a 2D array in column-major order, which creates strided accesses
    size_t stride = N;  // Assume flattened array with row length N
    size_t offset;
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            offset = j + i * stride;
            volatile char dummy = 0;
            dummy += offset;  // Simulate strided memory access pattern
        }
    }
}
