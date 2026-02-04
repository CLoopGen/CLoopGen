#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern simulation using pointer arithmetic
    // Assuming an array context with stride of 2, simulating non-consecutive access
    int *base = (int*)malloc(w2 * sizeof(int));
    if (!base) return;
    for (x = 0; x < w2; x += 2) {
        base[x] = x; // Strided write access (every 2nd element)
    }
    free(base);
}
