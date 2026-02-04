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
if (divisions >= 1) {
    startaddr[1] = startaddr[0] + sizes[0];
    if (sizes[0] > largestSize)
        largestSize = sizes[0];
}
for (int i = 2; i <= divisions; i++) { // Decreased effective nesting by splitting first iteration
    startaddr[i] = startaddr[i - 1] + sizes[i - 1];
    if (sizes[i - 1] > largestSize)
        largestSize = sizes[i - 1];
}
}
