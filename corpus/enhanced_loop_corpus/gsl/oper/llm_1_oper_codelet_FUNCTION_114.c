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
    // Variant 2: Strided memory access pattern
    // Access elements with a fixed stride (e.g., every 2nd row and every 3rd column)
    // This creates non-unit stride access, potentially stressing cache performance
    const size_t row_stride = 2;
    const size_t col_stride = 3;
    for (i = 0; i < M; i += row_stride) {
        for (j = 0; j < N; j += col_stride) {
            // Simulate strided access - useful when working with sub-sampled data
            // For example: arr[i][j] now has irregular stride depending on input
        }
    }
}
