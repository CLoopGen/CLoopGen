#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[16];
    for (j = 0; j < 16; ++j) {
        arr[j] = j * 2;
    }
    // Removes loop-carried dependencies: each iteration writes to a unique memory location
    // Introduces no RAW, WAR, or WAW dependencies across iterations, enabling potential vectorization
}
