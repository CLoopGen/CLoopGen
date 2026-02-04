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
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            // Reversed loop order: column-major traversal instead of row-major
            // Changes memory access pattern to be consecutive in the new inner loop (i.e., better spatial locality if backing array is row-major)
        }
    }
}
