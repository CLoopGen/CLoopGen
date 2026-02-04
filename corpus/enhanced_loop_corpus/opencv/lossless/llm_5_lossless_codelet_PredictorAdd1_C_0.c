#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_pixels;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int* buffer = (int*)malloc(num_pixels * sizeof(int));
    if (!buffer) return;
    for (i = 0; i < num_pixels; ++i) {
        buffer[i] = i * 2;
    }
    // Eliminate all loop-carried dependencies: each iteration writes to a unique memory location.
    // No RAW, WAR, or WAW dependencies between iterations — fully parallelizable.
    free(buffer);
}
