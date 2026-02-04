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
    uint64_t *array = (uint64_t*)malloc(N * sizeof(uint64_t));
    if (!array) return;
    for (i = 0; i < M; i++) {
        array[i] = i * i;
        for (j = i + 1; j < N; j++) {
            array[j] = array[j-1] + i; // Introduces RAW and WAW dependencies
        }
    }
    free(array);
}
