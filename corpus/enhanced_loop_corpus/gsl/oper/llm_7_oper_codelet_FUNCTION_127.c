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
    uint64_t* array = (uint64_t*)malloc(M * sizeof(uint64_t));
    for (i = 0; i < M; i++) {
        array[i] = i;
        for (j = 0; j < N; j++) {
            array[i] += j;
        }
    }
    // Introduce RAW dependency: use of array[i] after definition
    // Eliminate cross-iteration dependencies in outer loop by confining updates to array[i]
    // Inner loop has loop-carried dependency on array[i], but no inter-outer-loop-iteration dependency
    free(array);
}
