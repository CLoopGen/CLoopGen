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
    for (int i = 1; i <= divisions; i++) {
        int size_val = sizes[i - 1];
        startaddr[i] = startaddr[i - 1] + size_val;
        // Introduce artificial WAW and WAR dependency by splitting update of largestSize
        if (size_val > largestSize) {
            largestSize = size_val;  // WAW: Write-after-Write on largestSize across iterations
        }
        // Create a pseudo-read of current largestSize to introduce RAW within same iteration
        volatile int dummy = largestSize;
        (void)dummy;
    }
}
