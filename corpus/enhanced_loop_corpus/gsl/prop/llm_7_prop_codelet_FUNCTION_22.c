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
        array[i] = i + 1;
        for (j = 0; j < size2; j++) {
            // Introduce WAR hazard possibility by writing after read in next iteration
            if (i > 0) {
                array[i-1] += j; // Write after previous read – potential WAR with prior iteration
            }
        }
    }
    free(array);
    // Eliminated loop-carried dependency in inner loop by isolating side effects per i
}
