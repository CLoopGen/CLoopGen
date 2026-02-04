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
    // Variant 2: Strided memory access pattern, stepping through rows with fixed column offset
    size_t stride = N;  // Assume logical 2D array layout with row length N
    for (j = 0; j < N; j += 2) {  // Stride of 2 in the inner dimension
        for (i = 0; i < M; i++) {
            // Simulate accessing arr[i][j] with strided j
        }
    }
}
