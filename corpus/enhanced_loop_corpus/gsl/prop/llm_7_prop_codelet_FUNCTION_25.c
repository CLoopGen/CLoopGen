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
    if (!array) return;
    for (i = 0; i < M; i++) {
        array[i] = i;
        for (j = 0; j < N; j++) {
            array[i] = array[i] + j; // Read-after-write (RAW): each inner iteration reads what was written in previous iteration
        }
    }
    // Introduces loop-carried RAW dependency in inner loop
    // WAR and WAW on array[i] within inner loop
    // No cross-outer-loop dependency due to independent i indexing
    free(array);
}
