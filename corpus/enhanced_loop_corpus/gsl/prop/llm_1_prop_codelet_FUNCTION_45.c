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
    // Variant 2: Strided memory access pattern - iterate over transposed indices to simulate strided array traversal
    size_t stride = M > N ? M : N;
    for (j = 0; j < stride; j++) {
        for (i = 0; i < (j < M ? N : 0); i++) {
            // Simulate access with stride in outer dimension, e.g., accessing A[j][i] in row-major when j varies slowest
        }
    }
}
