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
for (int i = 0; i < divisions; i += 2) {
    if (i + 1 <= divisions) {
        startaddr[i + 1] = startaddr[i] + sizes[i];
        if (sizes[i] > largestSize)
            largestSize = sizes[i];
    }
    if (i + 2 <= divisions) {
        startaddr[i + 2] = startaddr[i + 1] + sizes[i + 1];
        if (sizes[i + 1] > largestSize)
            largestSize = sizes[i + 1];
    }
}
}
