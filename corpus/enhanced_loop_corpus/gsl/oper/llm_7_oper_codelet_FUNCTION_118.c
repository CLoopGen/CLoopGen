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
    uint64_t* array = (uint64_t*)calloc(N, sizeof(uint64_t));
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            // Introduce RAW (read-after-write) dependency: each iteration depends on previous write to array[j]
            array[j] = (i == 0) ? (j + 1) : array[j] + i;
        }
    }
    free(array);
}
