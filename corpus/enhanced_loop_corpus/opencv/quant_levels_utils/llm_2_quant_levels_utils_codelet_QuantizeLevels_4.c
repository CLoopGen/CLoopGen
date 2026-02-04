#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t data_size;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of iterating with stride 1, access elements with a fixed stride (e.g., 4)
    // Assuming 'data_size' represents number of elements and we're simulating array traversal
    size_t stride = 4;
    for (n = 0; n < data_size; n += stride) {
        // Simulate memory access at strided indices
        // (in a real scenario, this would touch an array like data[n])
        __asm__ volatile("" : : "r" (n) : "memory"); // Prevent optimization, simulate access
    }
}
