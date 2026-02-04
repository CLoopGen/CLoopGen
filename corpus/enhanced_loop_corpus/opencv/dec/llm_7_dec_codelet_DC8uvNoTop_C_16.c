#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8];
    for (i = 0; i < 8; ++i) {
        arr[i] = arr[(i + 7) % 8] + 1;
    }
    // Introduces loop-carried RAW dependency: each iteration reads value written 1 iteration ago
    // Creates a cyclic dependency across iterations (except first), increasing data coupling
    // Uses modulo indexing to safely access prior element with wraparound initialization behavior
}
