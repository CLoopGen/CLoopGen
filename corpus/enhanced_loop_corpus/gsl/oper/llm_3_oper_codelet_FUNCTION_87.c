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
    // Variant 2: Strided memory access pattern with reversed and non-unit stride traversal
    size_t stride = 2;
    size_t limit = (M + N + stride - 1) / stride * stride; // Ensure coverage with padding
    for (i = 0; i < limit; i += stride) {
        for (j = 0; j < N; j++) {
            size_t pos = ((i + j) % M) * stride; // Strided indirect-like access simulation
            __asm__ volatile("" : "+r" (pos) : : "memory"); // Placeholder for memory access effect
        }
    }
}
