#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int planes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *array = (int*)malloc(planes * sizeof(int));
    if (!array) return;
    for (int i = 0; i < planes; i++) {
        array[i] = i * 2;
    }
    // Eliminates loop-carried dependencies: each iteration writes to a unique memory location
    // No RAW, WAR, or WAW between iterations — fully parallelizable
    free(array);
}
