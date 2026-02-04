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
    uint64_t *array = (uint64_t*)calloc(N, sizeof(uint64_t));
    if (!array) return;
    for (i = 1; i < M; i++) {
        for (j = 0; j < ((i) < (N) ? (i) : (N)); j++) {
            array[j] = array[(j + 1) % N] + i; // Introduces WAW and RAW loop-carried dependencies
        }
    }
    free(array);
}
