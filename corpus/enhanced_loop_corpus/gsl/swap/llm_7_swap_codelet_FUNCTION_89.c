#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t *array = (uint64_t*)malloc(K * sizeof(uint64_t));
    if (array == NULL) return;
    for (i = 0; i < K; i++) {
        if (i == 0)
            array[i] = 1;
        else
            array[i] = array[i-1] + i; // Create RAW (read-after-write) loop-carried dependency
    }
    // Prevent unused variable warning and free memory
    volatile uint64_t sink = array[K-1];
    free(array);
}
