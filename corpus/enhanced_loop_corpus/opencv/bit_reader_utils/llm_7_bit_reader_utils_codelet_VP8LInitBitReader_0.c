#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t length;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t* array = (uint64_t*)malloc(length * sizeof(uint64_t));
    if (!array) return;
    for (i = 0; i < length; ++i) {
        if (i == 0)
            array[i] = 1;
        else
            array[i] = array[i-1] + i; // Introduce RAW loop-carried dependency: each iteration reads previous write
    }
    // Free memory to avoid leaks in realistic usage
    free(array);
}
