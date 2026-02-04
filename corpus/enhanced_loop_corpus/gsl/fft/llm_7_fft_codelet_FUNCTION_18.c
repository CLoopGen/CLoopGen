#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern  size_t m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t* arr = (size_t*)malloc(m * sizeof(size_t));
    if (!arr) return;
    for (i = 0; i < m; i++) {
        arr[i] = i;
        if (i > 0) {
            arr[i] += arr[i - 1]; // Introduce loop-carried RAW dependence: arr[i] depends on arr[i-1]
        }
    }
    free(arr);
    // This variant introduces a loop-carried flow dependence (RAW) creating sequential dependency
}
