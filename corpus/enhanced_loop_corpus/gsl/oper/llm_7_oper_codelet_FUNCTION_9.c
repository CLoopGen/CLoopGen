#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern  size_t tda;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp[2] = {0}; // Use array to break direct scalar dependencies
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            // Eliminate loop-carried dependency by using modulo indexing into temp
            // Create WAR-like scenario artificially via out-of-order potential (though no actual hazard due to independence)
            size_t idx = (i + j) % 2;
            temp[idx] = 2 * (i * tda + j) + 1;
            // Each write targets different slot based on (i+j), breaking sequential carry in k
            // No loop-carried dependency across iterations (except through memory aliasing, minimal)
        }
    }
}
