#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t* arr = (uint64_t*) malloc(K * sizeof(uint64_t));
    if (arr == NULL) return;
    for (i = 0; i < K; i++) {
        if (i == 0)
            arr[i] = 1;
        else
            arr[i] = arr[i-1] + i; // Introduce RAW (read-after-write) loop-carried dependency
    }
    // This variant creates a recurrence relation where each iteration depends on the previous (RAW)
    // Loop-carried dependence: arr[i] depends on arr[i-1], making parallelization difficult
    free(arr);
}
