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
    volatile uint64_t temp;
    uint64_t *sums = (uint64_t*)calloc(M, sizeof(uint64_t));
    for (i = 0; i < M; i++) {
        sums[i] = 0;
        for (j = 0; j < N; j++) {
            temp = i * j + 2; // Eliminate cross-iteration data dependencies; all operations are independent
            sums[i] += temp;  // WAW hazard avoided by privatizing sums[i]
        }
    }
    free(sums);
}
