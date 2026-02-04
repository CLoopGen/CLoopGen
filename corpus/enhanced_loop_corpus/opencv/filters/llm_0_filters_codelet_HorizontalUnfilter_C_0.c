#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Assuming an array 'data' of size at least width * stride
    // We simulate strided access with a step size (stride = 4)
    const int stride = 4;
    volatile uint32_t dummy = 0;
    for (i = 0; i < width; i += 1) {
        // Simulate strided access: indices 0, 4, 8, ... modulo array size
        int index = (i * stride) % width;
        dummy += index; // Prevent optimization away
    }
}
