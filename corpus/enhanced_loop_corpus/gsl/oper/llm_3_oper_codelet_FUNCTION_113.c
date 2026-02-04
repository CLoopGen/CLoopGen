#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern
    // Instead of iterating in natural order, access elements with a fixed stride
    // This simulates scenarios like accessing every K-th element or column-wise traversal
    const size_t STRIDE = 16; // Example stride value
    size_t max_elements = M * N;
    for (i = 0; i < STRIDE; i++) {
        for (j = i; j < max_elements; j += STRIDE) {
            // Simulate access at index j, creating a strided access pattern
            __asm__ volatile("" : "+g" (j) : : "memory"); // Prevent optimization
        }
    }
}
