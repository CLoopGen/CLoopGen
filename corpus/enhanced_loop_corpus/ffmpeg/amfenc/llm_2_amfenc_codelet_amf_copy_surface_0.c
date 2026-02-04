#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int planes;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Assuming there's an array 'data' of size sufficiently large
    // We simulate strided access by incrementing i with a fixed stride
    int stride = 4;
    for (i = 0; i < planes; i += stride) {
        // Simulated access: e.g., data[i] = i; if array were present
        // This reflects a non-unit stride traversal
    }
}
