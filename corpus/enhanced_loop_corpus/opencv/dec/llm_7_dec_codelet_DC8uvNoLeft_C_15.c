#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8];
    for (i = 0; i < 8; ++i) {
        arr[i] = i;
        if (i > 0) {
            arr[i] += arr[i-1]; // Introduces loop-carried RAW dependency: each iteration depends on prior iteration's result.
        }
    }
    // Creates a recurrence with loop-carried dependency, transforming independent iterations into a cumulative pattern.
}
