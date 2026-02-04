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
    uint64_t *array = (uint64_t*)malloc(size1 * sizeof(uint64_t));
    if (!array) return;
    for (i = 0; i < size1; i++) {
        array[i] = i * 2;
        for (j = 0; j < size2; j++) {
            // Introduce loop-carried dependence: each inner iteration updates same location
            array[i] += j;
        }
    }
    // Eliminate loop-carried dependence across outer loop via independent array indices
    // RAW dependencies within inner loop: j values accumulate into array[i]
    free(array);
}
