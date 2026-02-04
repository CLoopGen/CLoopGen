#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t loop_lim;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t* arr = (uint64_t*)malloc(loop_lim * sizeof(uint64_t));
    if (!arr) return;
    for (i = 0; i < loop_lim; i++) {
        if (i == 0)
            arr[i] = 1;
        else
            arr[i] = arr[i-1] + i; // Introduce loop-carried RAW (read-after-write) dependency
    }
    free(arr);
}
