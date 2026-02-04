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
    // Variant 2: Strided memory access pattern - simulate access with stride greater than 1
    size_t stride = 4; // Example stride
    size_t access_idx;
    for (i = 0; i < M; i += 1) {
        for (j = i + 1; j < N; j += stride) {  // Strided iteration in inner loop
            access_idx = j;  // Simulate use of strided access (e.g., array[j] with gaps)
            if (j + stride >= N) break; // Prevent overshoot
        }
    }
}
