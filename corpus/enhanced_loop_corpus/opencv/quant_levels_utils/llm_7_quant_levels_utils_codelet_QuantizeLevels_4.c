#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t data_size;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t *array = (uint64_t*)malloc(data_size * sizeof(uint64_t));
    if (!array) return;
    for (n = 0; n < data_size; ++n) {
        array[n] = n;
        if (n > 0) {
            array[n] += array[n-1]; // RAW dependency: current iteration reads previous value
        }
    }
    // Introduces loop-carried RAW dependency across array elements
    // Adds memory-based data dependency, making each iteration dependent on prior result
    free(array);
}
