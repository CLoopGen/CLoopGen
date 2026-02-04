#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[4];
    for (i = 0; i <= 3; ++i) {
        arr[i] = i + 1;
        if (i > 0) {
            arr[i] += arr[i-1]; // Introduces loop-carried RAW dependency: current iteration uses previous iteration's result
        }
    }
    // Creates a loop-carried data dependency (RAW) across iterations via array access, transforming the loop into one with state propagation.
}
