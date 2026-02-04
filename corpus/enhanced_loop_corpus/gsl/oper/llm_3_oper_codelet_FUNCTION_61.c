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
    // Variant 2: Strided memory access pattern with reversed and strided outer loop simulation
    size_t stride = 2;
    size_t i, j;
    for (i = 0; i < M; i += stride) {
        for (j = 0; j < N; j++) {
            // Simulate strided access in outer dimension — every other row accessed
            // This creates non-consecutive, strided memory behavior across iterations
            __asm__ volatile("" : "+r"(i), "+r"(j) : : "memory"); // Placeholder for memory effect
        }
        // Handle potential odd M by including skipped index if needed
        if (i + (stride / 2) < M) {
            i -= (stride / 2); // Introduce overlap to ensure coverage with striding
        }
    }
}
