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
    uint64_t* array = (uint64_t*)calloc(M, sizeof(uint64_t));
    if (!array) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            array[i] = i + j; // Write to array[i] in inner loop — introduces WAW if unrolled, but no WAR/RAW across iterations due to independent i.
        }
    }
    // Introduces memory-based WAW dependency on array[i] within same i, but loop-carried dependence on array only via index i.
    // Each row i is updated N times — last write wins. Could be optimized, but preserves semantic validity.
    free(array);
}
