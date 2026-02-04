#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[3];
    for (i = 0; i < 3; i++) {
        arr[i] = i * 2;
    }
    // Eliminates loop-carried dependencies: each iteration writes to a unique memory location
    // No RAW, WAR, or WAW dependencies between iterations, enabling full loop independence and potential vectorization
}
