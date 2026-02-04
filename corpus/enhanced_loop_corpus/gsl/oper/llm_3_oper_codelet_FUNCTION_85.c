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
    // Variant 2: Strided memory access pattern - step through indices with a fixed stride
    size_t stride = 4; // Example stride for scattered access
    size_t max_idx = M * N;
    for (i = 0; i < max_idx; i += stride) {
        for (j = 0; j < stride && (i + j) < max_idx; j++) {
            size_t idx = i + j; // Local consecutive within stride
            __asm__ volatile("" : "+r"(idx) : : "memory"); // Simulated access
        }
    }
}
