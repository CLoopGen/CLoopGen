#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[16];
    for (i = 0; i < 16; ++i) {
        arr[i] = i;
        if (i > 0) {
            arr[i] += arr[i - 1]; // Loop-carried RAW dependency: each iteration depends on previous result
        }
    }
    // Introduces loop-carried RAW dependency creating a cumulative sum pattern.
    // Eliminates any possibility of full loop parallelization due to dependency chain.
}
