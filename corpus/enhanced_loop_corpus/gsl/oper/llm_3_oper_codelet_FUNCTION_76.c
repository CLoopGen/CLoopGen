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
    // Variant 2: Strided memory access pattern, iterating down columns first with fixed stride
    size_t stride = M > N ? M : N; // Use larger dimension as effective stride
    for (j = 0; j < stride; j++) {
        for (i = 0; i < M; i++) {
            if (j < N) {
                // Access element in row i, column j — classic row-major but outer loop on j
                // This creates a strided access pattern in memory when N is large
            }
        }
    }
}
