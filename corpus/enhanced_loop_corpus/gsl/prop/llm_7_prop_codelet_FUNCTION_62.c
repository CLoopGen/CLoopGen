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
        array[i] = i + 1; // Write to distinct location (no loop-carried dep)
        for (j = 0; j < size2; j++) {
            // Introduce WAR-like pattern by reading neighbor in advance
            if (i > 0 && j == 0) {
                array[0] += array[i-1]; // Use of array[i-1] creates indirect dependence
            }
        }
    }

    free(array);
}
