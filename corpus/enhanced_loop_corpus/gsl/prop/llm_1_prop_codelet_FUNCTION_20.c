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
    // Instead of iterating j from 0 to N-1 normally, use a fixed stride (e.g., 2)
    // This creates non-unit stride memory access, simulating potential cache effects
    const size_t stride = 2;
    size_t j_stride;
    for (i = 0; i < M; i++) {
        for (j_stride = 0; j_stride < N; j_stride += stride) {
            // Simulate access at j_stride and possibly j_stride+1 if within bounds
            __asm__ volatile("" : "+r"(j_stride)); // Prevent optimization
            if (j_stride + 1 < N) {
                __asm__ volatile("" : "+r"(j_stride)); // Simulate second access
            }
        }
    }
}
