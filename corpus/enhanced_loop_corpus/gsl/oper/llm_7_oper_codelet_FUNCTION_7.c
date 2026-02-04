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
            array[i] = array[i] + j; // Loop-carried WAW and RAW dependency on array[i]: each iteration updates and reads same element
        }
    }
    free(array);
    // Introduces loop-carried dependencies (RAW and WAW) on array[i] within outer loop body
    // Data dependence between inner loop iterations through memory location
}
