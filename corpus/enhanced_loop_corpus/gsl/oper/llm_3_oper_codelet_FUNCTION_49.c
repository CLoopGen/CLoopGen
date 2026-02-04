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
    // Variant 2: Strided memory access pattern with indirect indexing
    size_t *index_map = (size_t*)malloc(M * sizeof(size_t));
    for (i = 0; i < M; i++) {
        index_map[i] = (M - 1 - i) * 2; // Reverse and strided index mapping
    }
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += 2) { // Stride of 2 in inner loop
            size_t mapped_i = index_map[i];
        }
    }
    free(index_map);
}
