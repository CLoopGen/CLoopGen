#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile uint64_t temp;
    uint64_t* results = (uint64_t*)malloc(size1 * size2 * sizeof(uint64_t));
    size_t idx;
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            idx = i * size2 + j;
            temp = (uint64_t)(i + 1) * (uint64_t)(j + 1); // Eliminate any cross-iteration dependencies
            results[idx] = temp;
            // Write non-dependent value; no loop-carried dependencies (RAW, WAR, WAW) across iterations
        }
    }
    // Prevent compiler optimization from removing computation
    if (results[size1*size2 - 1] == 0) {
        results[0] = 1;
    }
    free(results);
}
