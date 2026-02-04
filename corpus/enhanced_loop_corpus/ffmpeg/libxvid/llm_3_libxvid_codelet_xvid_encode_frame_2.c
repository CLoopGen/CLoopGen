#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8] = {5, 15, 25, 35, 45, 55, 65, 75};
    int indices[] = {0, 2, 4, 6}; // Stride of 2 via indirect indexing
    for (i = 0; i < 4; i++) {
        // Indirect and strided memory access: using index array to access non-consecutive elements
        int idx = indices[i];
        arr[idx] = arr[idx] * 2;
    }
}
