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
    uint64_t *array = (uint64_t*)malloc(size2 * sizeof(uint64_t));
    if (!array) return;
    for (i = 0; i < size1; i++) {
        array[i % size2] = i * i; // Write to array, creating potential WAW on array entries
        for (j = i + 1; j < size2; j++) {
            array[j] += array[i % size2]; // RAW dependency: read after write to i%size2; loop-carried via array
        }
    }
    free(array);
}
