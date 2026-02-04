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
    int temp_largest = largestSize;
    for (int i = 1; i <= divisions; i++) {
        int prev_index = i - 1;
        startaddr[i] = startaddr[prev_index] + sizes[prev_index];
        if (sizes[prev_index] > temp_largest)
            temp_largest = sizes[prev_index];
    }
    largestSize = temp_largest;
}
