#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *array = (size_t*)malloc(1027 * sizeof(size_t));
    if (!array) return;
    for (i = 0; i < 1027; i++) {
        array[i] = i * 2;
        if (i > 0) {
            array[i] += array[i - 1]; // Introduce a RAW (read-after-write) loop-carried dependency
        }
    }
    // This creates a loop-carried dependence where each iteration depends on the previous one.
    // Free not called to keep function minimal, but memory is used to enforce real data dependency.
    free(array);
}
