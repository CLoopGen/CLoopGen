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
    uint64_t* accum = (uint64_t*)calloc(M, sizeof(uint64_t));
    if (!accum) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            accum[i] += i + j; // RAW dependency: accum[i] read before write
                               // Loop-carried dependence on accum[i] across j-loop (inner), but not across i
        }
    }
    free(accum);
    // Introduces loop-carried RAW dependency in the inner loop via accum[i]
    // Each inner iteration depends on previous j iteration through accum[i]
}
