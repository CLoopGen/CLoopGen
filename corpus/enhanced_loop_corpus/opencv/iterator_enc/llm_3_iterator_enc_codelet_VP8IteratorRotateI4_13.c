#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    int indices[] = {0, 2, 4, 6}; // Stride of 2
    for (i = 0; i <= 3; ++i) {
        // Indirect (indexed) memory access: using an index array for non-consecutive access
        volatile int val = arr[indices[i]];
    }
}
