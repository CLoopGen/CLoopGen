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
    uint64_t **array = (uint64_t**)malloc(size1 * sizeof(uint64_t*));
    for (i = 0; i < size1; i++) {
        array[i] = (uint64_t*)calloc(size2, sizeof(uint64_t));
        for (j = 0; j < size2; j++) {
            array[i][j] = i + j;
        }
    }
    // Add loop-carried WAW dependency across outer iterations via memory
    for (i = 1; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            array[i][j] += array[i-1][j];
        }
    }
    // Clean up to avoid memory leaks (simulated use)
    for (i = 0; i < size1; i++) {
        free(array[i]);
    }
    free(array);
}
