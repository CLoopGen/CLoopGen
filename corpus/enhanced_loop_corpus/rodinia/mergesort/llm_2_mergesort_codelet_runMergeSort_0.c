#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int divisions;
extern int *sizes;
extern int *startaddr;
extern int largestSize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (unrolled by factor 2)
    // Process two iterations at a time to modify access pattern
    int i = 1;
    for (; i <= divisions - 1; i += 2) {
        startaddr[i] = startaddr[i - 1] + sizes[i - 1];
        if (sizes[i - 1] > largestSize)
            largestSize = sizes[i - 1];

        startaddr[i + 1] = startaddr[i] + sizes[i];
        if (sizes[i] > largestSize)
            largestSize = sizes[i];
    }
    // Handle leftover iteration if divisions is odd
    if (i <= divisions) {
        startaddr[i] = startaddr[i - 1] + sizes[i - 1];
        if (sizes[i - 1] > largestSize)
            largestSize = sizes[i - 1];
    }
}
