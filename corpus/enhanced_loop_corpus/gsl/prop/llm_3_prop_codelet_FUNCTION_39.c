#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern
    // Traverse the j-loop with a fixed stride (e.g., 2), creating non-consecutive access
    const size_t stride = 2;
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j += stride) {
            // Simulate strided access, e.g., processing every second element
            __asm volatile("" : : "r" (i), "r" (j) : "memory"); // placeholder for actual data access
        }
        // Handle remainder if size2 is odd
        if (stride > 1 && (size2 % stride) != 0) {
            j = size2 - 1;
            __asm volatile("" : : "r" (i), "r" (j) : "memory");
        }
    }
}
