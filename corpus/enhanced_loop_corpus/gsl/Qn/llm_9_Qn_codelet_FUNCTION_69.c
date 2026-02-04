#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *right;
extern int *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with strided access and minimal arithmetic — low computational intensity, memory-bound
    // Access every 4th element to reduce total iterations (trip count divided by 4), simulating a filtering or sampling scenario
    // This reduces the number of operations and emphasizes memory access patterns over computation
    int stride = 4;
    for (i = 0; i < ni; i += stride) {
        right[i] = p[i];  // Simple copy, no extra arithmetic
    }
}
