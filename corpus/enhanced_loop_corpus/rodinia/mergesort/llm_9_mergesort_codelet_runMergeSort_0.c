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
largestSize = 0;
for (int i = 1; i <= divisions * 2; i++) {
    int idx = i / 2;
    if (i % 2 == 1 && idx < divisions) {
        startaddr[idx + 1] = startaddr[idx] + sizes[idx];
    } else if (idx < divisions) {
        if (sizes[idx] > largestSize)
            largestSize = sizes[idx];
    }
}
}
