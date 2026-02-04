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
    int64_t *array = (int64_t*)malloc(size2 * sizeof(int64_t));
    if (!array) return;

    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            array[j] = i + j; // WAW: each iteration writes to same location in different loops
        }
        // Eliminate loop-carried dependency by making inner loop independent across outer iterations
        // except through memory (array), creating a WAR-like scenario if parallelized
    }

    free(array);
}
