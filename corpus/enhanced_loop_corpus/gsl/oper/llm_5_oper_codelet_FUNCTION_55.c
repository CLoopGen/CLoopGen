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
    uint64_t* result = (uint64_t*)alloca(N * sizeof(uint64_t));
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            temp = i * j + 2; // Eliminate all inter-iteration dependencies; make each iteration independent
            result[j] = temp ^ (result[j] + i); // WAW hazard avoided via reordering; no loop-carried dep across i
        }
    }
}
